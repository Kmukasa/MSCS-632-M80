import random
import json
import os
import sys
from typing import Dict, List, Tuple, Optional

class Employee:
    """Represents an employee with their name, shift preferences, and assigned shifts."""
    
    def __init__(self, name: str):
        self.name = name
        self.preferences = {}  # day -> shift preference
        self.assigned_shifts = {}  # day -> shift assignment
        self.working_days = 0  # count of days worked this week
    
    def add_preference(self, day: str, shift: str):
        """Add a shift preference for a specific day."""
        self.preferences[day] = shift
    
    def assign_shift(self, day: str, shift: str):
        """Assign an employee to a shift on a specific day."""
        if day not in self.assigned_shifts:
            self.assigned_shifts[day] = shift
            self.working_days += 1
            return True
        return False
    
    def is_available(self, day: str) -> bool:
        """Check if employee is available on a specific day."""
        return day not in self.assigned_shifts
    
    def can_work_more(self) -> bool:
        """Check if employee can work more days (max 5 per week)."""
        return self.working_days < 5

class EmployeeScheduler:
    """Main application class for managing employee scheduling."""
    
    def __init__(self, json_file="employee_data.json"):
        self.employees = []
        self.days = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
        self.shifts = ['Morning', 'Afternoon', 'Evening']
        self.schedule = {}  # day -> shift -> list of employees
        
        # Initialize schedule structure
        for day in self.days:
            self.schedule[day] = {}
            for shift in self.shifts:
                self.schedule[day][shift] = []
        
        # Load employee data from JSON file
        self.load_employee_data(json_file)
    
    def load_employee_data(self, json_file_path="employee_data.json"):
        """Load employee data from JSON file."""
        try:
            # Get the directory of the current script
            script_dir = os.path.dirname(os.path.abspath(__file__))
            json_path = os.path.join(script_dir, json_file_path)
            
            with open(json_path, 'r') as file:
                data = json.load(file)
            
            # Load employees from JSON data
            for employee_name, preferences in data["employees"].items():
                employee = Employee(employee_name)
                for day, shift in preferences.items():
                    employee.add_preference(day, shift)
                self.employees.append(employee)
            
            print(f"Successfully loaded {len(self.employees)} employees from {json_file_path}")
            
        except FileNotFoundError:
            print(f"Error: Could not find {json_file_path}")
            print("Please ensure the JSON file exists in the same directory as the script.")
            exit(1)
        except json.JSONDecodeError as e:
            print(f"Error: Invalid JSON format in {json_file_path}")
            print(f"JSON Error: {e}")
            exit(1)
        except KeyError as e:
            print(f"Error: Missing required key in JSON file: {e}")
            print("JSON file should have 'employees' key with employee data.")
            exit(1)
        except Exception as e:
            print(f"Error loading employee data: {e}")
            exit(1)
    
    def display_employee_input(self):
        """Display the employee input data."""
        print("=" * 80)
        print("EMPLOYEE SCHEDULER - INPUT DATA")
        print("=" * 80)
        print()
        
        for i, employee in enumerate(self.employees, 1):
            print(f"Employee {i}: {employee.name}")
            print("Shift Preferences:")
            for day in self.days:
                if day in employee.preferences:
                    print(f"  {day}: {employee.preferences[day]}")
                else:
                    print(f"  {day}: None")
            print()
    
    def display_employee_summary(self):
        """Display a summary of employees and their working days."""
        print("EMPLOYEE SUMMARY:")
        print("-" * 40)
        for employee in self.employees:
            print(f"{employee.name}: {employee.working_days} days assigned")
        print()
    
    def validate_constraints(self):
        """Validate that all scheduling constraints are met."""
        print("CONSTRAINT VALIDATION:")
        print("-" * 40)
        
        # Check 1: No employee works more than 1 shift per day
        double_shift_violations = []
        for employee in self.employees:
            for day in self.days:
                if day in employee.assigned_shifts:
                    # Count how many shifts this employee has on this day
                    day_shifts = 0
                    for shift in self.shifts:
                        if employee in self.schedule[day][shift]:
                            day_shifts += 1
                    if day_shifts > 1:
                        double_shift_violations.append(f"{employee.name} on {day}")
        
        if double_shift_violations:
            print("VIOLATION: Employees working multiple shifts per day:")
            for violation in double_shift_violations:
                print(f"   - {violation}")
        else:
            print("No employee works more than 1 shift per day")
        
        # Check 2: No employee works more than 5 days per week
        max_days_violations = []
        for employee in self.employees:
            if employee.working_days > 5:
                max_days_violations.append(f"{employee.name}: {employee.working_days} days")
        
        if max_days_violations:
            print("VIOLATION: Employees working more than 5 days:")
            for violation in max_days_violations:
                print(f"   - {violation}")
        else:
            print("No employee works more than 5 days per week")
        
        # Check 3: Exactly 2 employees per shift per day
        incorrect_staffing = []
        for day in self.days:
            for shift in self.shifts:
                employee_count = len(self.schedule[day][shift])
                if employee_count != 2:
                    incorrect_staffing.append(f"{day} {shift}: {employee_count} employees")
        
        if incorrect_staffing:
            print("VIOLATION: Shifts with incorrect staffing (should have exactly 2 employees):")
            for violation in incorrect_staffing:
                print(f"   - {violation}")
        else:
            print("All shifts have exactly 2 employees")
        
        # Summary
        total_violations = len(double_shift_violations) + len(max_days_violations) + len(incorrect_staffing)
        if total_violations == 0:
            print("\n ALL CONSTRAINTS SATISFIED!")
        else:
            print(f"\n  {total_violations} constraint violations found")
        
        print()
    
    def generate_schedule(self):
        """Generate the weekly schedule using the scheduling algorithm."""
        if len(self.employees) < 2:
            print("Error: At least 2 employees are required to generate a schedule.")
            return
        
        print("GENERATING SCHEDULE...")
        print("-" * 40)
        
        # Reset schedule and employee assignments
        self.reset_schedule()
        
        # Phase 1: Initial assignment based on preferences
        print("Phase 1: Initial assignment based on preferences")
        self.initial_assignment()
        
        # Phase 2: Fill understaffed shifts
        print("Phase 2: Filling understaffed shifts")
        self.fill_understaffed_shifts()
        
        # Phase 3: Resolve conflicts
        print("Phase 3: Resolving conflicts")
        self.resolve_conflicts()
        
        # Final check and fill any remaining understaffed shifts
        print("Final check: Ensuring all shifts have at least 2 employees")
        self.final_fill_understaffed()
        
        print("Schedule generation completed!")
        print()
    
    def reset_schedule(self):
        """Reset the schedule and employee assignments."""
        for day in self.days:
            for shift in self.shifts:
                self.schedule[day][shift] = []
        
        for employee in self.employees:
            employee.assigned_shifts = {}
            employee.working_days = 0
    
    def initial_assignment(self):
        """Phase 1: Assign employees to their preferred shifts."""
        for employee in self.employees:
            for day, preferred_shift in employee.preferences.items():
                if employee.can_work_more() and employee.is_available(day):
                    self.schedule[day][preferred_shift].append(employee)
                    employee.assign_shift(day, preferred_shift)
    
    def fill_understaffed_shifts(self):
        """Phase 2: Fill shifts to have exactly 2 employees, prioritizing unscheduled employees."""
        # Keep iterating until all shifts have exactly 2 employees or no more employees available
        max_iterations = 20  # Prevent infinite loops
        iteration = 0
        
        while iteration < max_iterations:
            understaffed_found = False
            
            for day in self.days:
                for shift in self.shifts:
                    current_count = len(self.schedule[day][shift])
                    if current_count < 2:
                        understaffed_found = True
                        needed = 2 - current_count
                        
                        # Find available employees who can work this day
                        available_employees = [
                            emp for emp in self.employees 
                            if emp.can_work_more() and emp.is_available(day)
                        ]
                        
                        if available_employees:
                            # Prioritize employees with fewer working days (unscheduled employees first)
                            available_employees.sort(key=lambda x: x.working_days)
                            
                            # Assign exactly the number needed (up to 2 total)
                            for i in range(min(needed, len(available_employees))):
                                emp = available_employees[i]
                                self.schedule[day][shift].append(emp)
                                emp.assign_shift(day, shift)
                                break  # Only assign one employee per iteration to avoid conflicts
                    
                    # If shift has more than 2 employees, remove excess (keep first 2)
                    elif current_count > 2:
                        # Remove excess employees (keep the first 2)
                        excess_employees = self.schedule[day][shift][2:]
                        for emp in excess_employees:
                            self.schedule[day][shift].remove(emp)
                            # Remove from employee's assigned shifts
                            if day in emp.assigned_shifts:
                                del emp.assigned_shifts[day]
                                emp.working_days -= 1
            
            # If no understaffed shifts found, we're done
            if not understaffed_found:
                break
                
            iteration += 1
    
    def resolve_conflicts(self):
        """Phase 3: Resolve conflicts and ensure exactly 2 employees per shift."""
        # First, try to fill any remaining understaffed shifts
        for day in self.days:
            for shift in self.shifts:
                current_count = len(self.schedule[day][shift])
                if current_count < 2:
                    needed = 2 - current_count
                    
                    # Find available employees who can work this day
                    available_employees = [
                        emp for emp in self.employees 
                        if emp.can_work_more() and emp.is_available(day)
                    ]
                    
                    if available_employees:
                        # Sort by working days (prioritize those with fewer days)
                        available_employees.sort(key=lambda x: x.working_days)
                        
                        # Assign exactly the number needed (up to 2 total)
                        for i in range(min(needed, len(available_employees))):
                            emp = available_employees[i]
                            self.schedule[day][shift].append(emp)
                            emp.assign_shift(day, shift)
                
                # Ensure shift has exactly 2 employees (remove excess if needed)
                elif current_count > 2:
                    # Remove excess employees (keep the first 2)
                    excess_employees = self.schedule[day][shift][2:]
                    for emp in excess_employees:
                        self.schedule[day][shift].remove(emp)
                        # Remove from employee's assigned shifts
                        if day in emp.assigned_shifts:
                            del emp.assigned_shifts[day]
                            emp.working_days -= 1
        
        # Then, try to assign remaining employees to understaffed shifts only
        for employee in self.employees:
            if employee.working_days < 5:  # Employee can still work more days
                # Try to find understaffed shifts
                for day in self.days:
                    if employee.is_available(day):
                        for shift in self.shifts:
                            # Only assign to shifts that need more people (less than 2)
                            if len(self.schedule[day][shift]) < 2:
                                self.schedule[day][shift].append(employee)
                                employee.assign_shift(day, shift)
                                break
                        if not employee.is_available(day):
                            break
    
    def final_fill_understaffed(self):
        """Final pass to ensure all shifts have exactly 2 employees."""
        # Keep trying until all shifts have exactly 2 employees or no more employees available
        max_attempts = 50
        attempt = 0
        
        while attempt < max_attempts:
            understaffed_shifts = []
            overstaffed_shifts = []
            
            # Find all shifts that need adjustment
            for day in self.days:
                for shift in self.shifts:
                    current_count = len(self.schedule[day][shift])
                    if current_count < 2:
                        understaffed_shifts.append((day, shift))
                    elif current_count > 2:
                        overstaffed_shifts.append((day, shift))
            
            # First, remove excess employees from overstaffed shifts
            for day, shift in overstaffed_shifts:
                excess_employees = self.schedule[day][shift][2:]
                for emp in excess_employees:
                    self.schedule[day][shift].remove(emp)
                    # Remove from employee's assigned shifts
                    if day in emp.assigned_shifts:
                        del emp.assigned_shifts[day]
                        emp.working_days -= 1
            
            if not understaffed_shifts:
                break  # All shifts are properly staffed
            
            # Try to fill each understaffed shift
            for day, shift in understaffed_shifts:
                needed = 2 - len(self.schedule[day][shift])
                
                # Find available employees
                available_employees = [
                    emp for emp in self.employees 
                    if emp.can_work_more() and emp.is_available(day)
                ]
                
                if available_employees:
                    # Sort by working days (prioritize those with fewer days)
                    available_employees.sort(key=lambda x: x.working_days)
                    
                    # Assign exactly the number needed (up to 2 total)
                    for i in range(min(needed, len(available_employees))):
                        emp = available_employees[i]
                        self.schedule[day][shift].append(emp)
                        emp.assign_shift(day, shift)
                        break  # Only assign one per attempt
            
            attempt += 1
    
    def display_schedule(self):
        """Display the generated schedule in a table format."""
        print("=" * 80)
        print("WEEKLY EMPLOYEE SCHEDULE")
        print("=" * 80)
        print()
        
        # Create table header
        print(f"{'Day':<12} {'Morning':<20} {'Afternoon':<20} {'Evening':<20}")
        print("-" * 80)
        
        # Create schedule rows
        for day in self.days:
            morning_employees = [emp.name for emp in self.schedule[day]['Morning']]
            afternoon_employees = [emp.name for emp in self.schedule[day]['Afternoon']]
            evening_employees = [emp.name for emp in self.schedule[day]['Evening']]
            
            morning_text = ', '.join(morning_employees) if morning_employees else 'None'
            afternoon_text = ', '.join(afternoon_employees) if afternoon_employees else 'None'
            evening_text = ', '.join(evening_employees) if evening_employees else 'None'
            
            print(f"{day:<12} {morning_text:<20} {afternoon_text:<20} {evening_text:<20}")
        
        print()
        print("=" * 80)
    
    def run(self):
        """Run the application."""
        # Display input data
        self.display_employee_input()
        
        # Generate schedule
        self.generate_schedule()
        
        # Display the final schedule
        self.display_schedule()
        
        # Display employee summary
        self.display_employee_summary()
        
        # Validate constraints
        self.validate_constraints()

if __name__ == "__main__":
    # Check for command line argument for JSON file
    json_file = "employee_data.json"
    if len(sys.argv) > 1:
        json_file = sys.argv[1]
        print(f"Using JSON file: {json_file}")
    
    app = EmployeeScheduler(json_file)
    app.run()

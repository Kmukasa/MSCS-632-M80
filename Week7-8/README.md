# Employee Scheduler

A console-based employee scheduling application that generates weekly work schedules based on employee shift preferences.

## Features

- **JSON Input**: Load employee data from JSON files
- **Constraint Validation**: Ensures exact staffing requirements - exactly 2 employees per shift, one shift per employee per day & employee max days is 5
- **Conflict Resolution**: Automatically resolves scheduling conflicts
- **Flexible Input**: Support for different employee datasets in json format

## Usage

### Basic Usage

```bash
python3 employee_scheduler.py
```

This will use the default `employee_data.json` file that I generated but a different file can be added.

### Custom JSON File

```bash
python3 employee_scheduler.py your_employees.json
```

## JSON Format

The JSON file should follow this structure:

```json
{
  "employees": {
    "EmployeeName": {
      "Monday": "Morning",
      "Tuesday": "Afternoon",
      "Wednesday": "Evening",
      "Thursday": "Morning",
      "Friday": "Afternoon"
    }
  }
}
```

### Valid Shift Values

- `"Morning"`
- `"Afternoon"`
- `"Evening"`
- `null` or omit days for no preference

## UI

The following program outputs the employee preference data, week schedule and summary if days worked to the terminal in a readable format.

## Constraints

- **Exact Staffing**: Exactly 2 employees per shift per day
- **Maximum Days**: No employee works more than 5 days per week
- **No Double Shifts**: No employee works more than 1 shift per day

## Example Output

The application will display:

1. **Input Data**: All employee names and their shift preferences
2. **Generation Process**: Shows the 3 phases of scheduling
3. **Final Schedule**: A formatted table showing who works each shift each day
4. **Employee Summary**: Shows how many days each employee is assigned
5. **Constraint Validation**: Verifies all scheduling constraints are met

## Constraint Validation

The application automatically validates that all constraints are satisfied:

- **No Double Shifts**: No employee works more than 1 shift per day
- **Maximum Days**: No employee works more than 5 days per week
- **Exact Staffing**: All shifts have exactly 2 employees

If any constraints are violated, the application will report specific violations.

## Files

- `employee_scheduler.py` - Main application
- `employee_data.json` - Default employee data (15 employees)

## Scheduling Algorithm

The scheduling algorithm has been enhanced to ensure exactly 2 employees per shift while prioritizing unscheduled employees. The algorithm makes multiple passes to fill understaffed shifts, removes excess employees from overstaffed shifts, and includes automatic verification that all business rules are satisfied with graceful handling of edge cases.

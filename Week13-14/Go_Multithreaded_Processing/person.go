package main

// Person represents a person with a name.
// This is a simple data structure used in the data processing system.
type Person struct {
	Name string
}

// NewPerson creates a new Person with the given name.
func NewPerson(name string) *Person {
	return &Person{Name: name}
}

// String returns a string representation of the person.
func (p *Person) String() string {
	return p.Name
}


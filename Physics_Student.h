// ============================================================================
// Physics_Student.h
// Derived class: a Student in the physics program. Adds a "concentration".
// ============================================================================
#ifndef PHYSICS_STUDENT_H
#define PHYSICS_STUDENT_H

#include "Student.h"

// The allowed physics concentrations.
enum class PhysicsConcentration { Biophysics, EarthAndPlanetarySciences, Unknown };

inline std::string toString(PhysicsConcentration c)
{
    switch (c)
    {
        case PhysicsConcentration::Biophysics:                return "Biophysics";
        case PhysicsConcentration::EarthAndPlanetarySciences: return "Earth and Planetary Sciences";
        default:                                              return "Unknown";
    }
}

class Physics_Student : public Student
{
public:
    Physics_Student() : Student(), concentration_(PhysicsConcentration::Unknown) {}
    virtual ~Physics_Student() {}

    PhysicsConcentration getConcentration() const { return concentration_; }
    void setConcentration(PhysicsConcentration c) { concentration_ = c; }

    // Writes the common fields, then the concentration.
    void write(std::ostream &out) const override
    {
        out << "Major: Physics\n";
        Student::write(out);
        out << "Concentration: " << toString(concentration_) << "\n";
    }

private:
    PhysicsConcentration concentration_;
};

#endif

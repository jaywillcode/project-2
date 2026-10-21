// ============================================================================
// Student.h
// Base class holding every field common to all students. All functions are
// defined inside the class (implicitly inline)
// ============================================================================
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <ostream>
#include <stdexcept>

// Academic term, used for both enrollment and graduation.
enum class Semester { Spring, Summer, Fall, Winter, Unknown };

// Degree level of the student.
enum class DegreeLevel { Undergrad, Grad, Unknown };

// Enum -> text helpers. "inline" lets them live in a header safely.
inline std::string toString(Semester s)
{
    switch (s)
    {
        case Semester::Spring: return "Spring";
        case Semester::Summer: return "Summer";
        case Semester::Fall:   return "Fall";
        case Semester::Winter: return "Winter";
        default:               return "Unknown";
    }
}

inline std::string toString(DegreeLevel d)
{
    switch (d)
    {
        case DegreeLevel::Undergrad: return "Undergrad";
        case DegreeLevel::Grad:      return "Grad";
        default:                     return "Unknown";
    }
}

class Student
{
public:
    // Default constructor: every field gets a sensible "unset" value.
    Student()
        : firstName_("Unknown"), lastName_("Unknown"), gpa_(0.0),
          graduationYear_(0), graduationSemester_(Semester::Unknown),
          enrolledYear_(0), enrolledSemester_(Semester::Unknown),
          degreeLevel_(DegreeLevel::Unknown) {}

    // Virtual so deleting a derived object through a Student* is safe.
    // Nothing here is allocated with new (std::string frees itself).
    virtual ~Student() {}

    // ---- Getters ----------------------------------------------------------
    std::string getFirstName() const          { return firstName_; }
    std::string getLastName() const           { return lastName_; }
    std::string getFullName() const           { return firstName_ + " " + lastName_; }
    double      getGPA() const                { return gpa_; }
    int         getGraduationYear() const     { return graduationYear_; }
    Semester    getGraduationSemester() const { return graduationSemester_; }
    int         getEnrolledYear() const       { return enrolledYear_; }
    Semester    getEnrolledSemester() const   { return enrolledSemester_; }
    DegreeLevel getDegreeLevel() const        { return degreeLevel_; }

    // ---- Setters ----------------------------------------------------------
    void setName(const std::string &first, const std::string &last)
    {
        firstName_ = first;
        lastName_  = last;
    }

    // GPA must be between 0.0 and 4.0.
    void setGPA(double gpa)
    {
        if (gpa < 0.0 || gpa > 4.0)
            throw std::out_of_range("GPA must be between 0.0 and 4.0");
        gpa_ = gpa;
    }

    // String overload so setGPA("3.9") works, as in the sample code.
    void setGPA(const std::string &gpa) { setGPA(std::stod(gpa)); }

    void setGraduationYear(int year)       { graduationYear_ = year; }
    void setGraduationSemester(Semester s) { graduationSemester_ = s; }
    void setEnrolledYear(int year)         { enrolledYear_ = year; }
    void setEnrolledSemester(Semester s)   { enrolledSemester_ = s; }
    void setDegreeLevel(DegreeLevel level) { degreeLevel_ = level; }

    // ---- Output -----------------------------------------------------------
    // Writes this student's info to any stream (file, cout, ...).
    // Virtual so derived classes can add their own fields.
    virtual void write(std::ostream &out) const
    {
        out << "Name: "                << getFullName()                 << "\n"
            << "GPA: "                 << gpa_                          << "\n"
            << "Level: "               << toString(degreeLevel_)        << "\n"
            << "Enrolled: "            << toString(enrolledSemester_)   << " "
                                       << enrolledYear_                 << "\n"
            << "Expected Graduation: " << toString(graduationSemester_) << " "
                                       << graduationYear_               << "\n";
    }

private:
    std::string firstName_;
    std::string lastName_;
    double      gpa_;
    int         graduationYear_;
    Semester    graduationSemester_;
    int         enrolledYear_;
    Semester    enrolledSemester_;
    DegreeLevel degreeLevel_;
};

#endif

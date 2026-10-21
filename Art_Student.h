// ============================================================================
// Art_Student.h
// Derived class: a Student in the art program. Adds an "art emphasis".
// ============================================================================
#ifndef ART_STUDENT_H
#define ART_STUDENT_H

#include "Student.h"

// The three allowed art emphases.
enum class ArtEmphasis { ArtStudio, ArtHistory, ArtEducation, Unknown };

inline std::string toString(ArtEmphasis e)
{
    switch (e)
    {
        case ArtEmphasis::ArtStudio:    return "Art Studio";
        case ArtEmphasis::ArtHistory:   return "Art History";
        case ArtEmphasis::ArtEducation: return "Art Education";
        default:                        return "Unknown";
    }
}

class Art_Student : public Student
{
public:
    // Base-class default constructor runs first automatically.
    Art_Student() : Student(), artEmphasis_(ArtEmphasis::Unknown) {}
    virtual ~Art_Student() {}

    ArtEmphasis getArtEmphasis() const       { return artEmphasis_; }
    void setArtEmphasis(ArtEmphasis e)       { artEmphasis_ = e; }

    // Writes the common fields, then the art emphasis.
    void write(std::ostream &out) const override
    {
        out << "Major: Art\n";
        Student::write(out);
        out << "Art Emphasis: " << toString(artEmphasis_) << "\n";
    }

private:
    ArtEmphasis artEmphasis_;
};

#endif

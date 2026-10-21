// ============================================================================
// main.cpp
// Creates 5 Art_Student and 5 Physics_Student objects on the heap, stores the
// pointers in two separate std::vectors, fills in values, writes everything
// to "student_info.dat", then frees all memory.
// ============================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "Art_Student.h"
#include "Physics_Student.h"

int main()
{
    std::vector<Art_Student *>     art_students;
    std::vector<Physics_Student *> physics_students;

    // ---- Allocate 5 of each with new ---------------------------------------
    for (int i = 0; i < 5; i++)
    {
        art_students.push_back(new Art_Student);
        physics_students.push_back(new Physics_Student);
    }

    // ---- Fill in the art students -------------------------------------------
    art_students[0]->setName("Frida", "Moreno");
    art_students[0]->setGPA("3.9");                 // string overload, as in the sample
    art_students[0]->setEnrolledYear(2022);
    art_students[0]->setEnrolledSemester(Semester::Fall);
    art_students[0]->setGraduationYear(2026);
    art_students[0]->setGraduationSemester(Semester::Spring);
    art_students[0]->setDegreeLevel(DegreeLevel::Undergrad);
    art_students[0]->setArtEmphasis(ArtEmphasis::ArtStudio);

    art_students[1]->setName("Georgia", "Chen");
    art_students[1]->setGPA(3.4);
    art_students[1]->setEnrolledYear(2023);
    art_students[1]->setEnrolledSemester(Semester::Spring);
    art_students[1]->setGraduationYear(2027);
    art_students[1]->setGraduationSemester(Semester::Fall);
    art_students[1]->setDegreeLevel(DegreeLevel::Undergrad);
    art_students[1]->setArtEmphasis(ArtEmphasis::ArtHistory);

    art_students[2]->setName("Diego", "Navarro");
    art_students[2]->setGPA(3.7);
    art_students[2]->setEnrolledYear(2024);
    art_students[2]->setEnrolledSemester(Semester::Fall);
    art_students[2]->setGraduationYear(2026);
    art_students[2]->setGraduationSemester(Semester::Spring);
    art_students[2]->setDegreeLevel(DegreeLevel::Grad);
    art_students[2]->setArtEmphasis(ArtEmphasis::ArtEducation);

    art_students[3]->setName("Mina", "Okafor");
    art_students[3]->setGPA(3.1);
    art_students[3]->setEnrolledYear(2021);
    art_students[3]->setEnrolledSemester(Semester::Fall);
    art_students[3]->setGraduationYear(2025);
    art_students[3]->setGraduationSemester(Semester::Summer);
    art_students[3]->setDegreeLevel(DegreeLevel::Undergrad);
    art_students[3]->setArtEmphasis(ArtEmphasis::ArtStudio);

    art_students[4]->setName("Leo", "Brandt");
    art_students[4]->setGPA(3.95);
    art_students[4]->setEnrolledYear(2025);
    art_students[4]->setEnrolledSemester(Semester::Spring);
    art_students[4]->setGraduationYear(2027);
    art_students[4]->setGraduationSemester(Semester::Spring);
    art_students[4]->setDegreeLevel(DegreeLevel::Grad);
    art_students[4]->setArtEmphasis(ArtEmphasis::ArtHistory);

    // ---- Fill in the physics students ---------------------------------------
    physics_students[0]->setName("Marie", "Lindqvist");
    physics_students[0]->setGPA(3.8);
    physics_students[0]->setEnrolledYear(2022);
    physics_students[0]->setEnrolledSemester(Semester::Fall);
    physics_students[0]->setGraduationYear(2026);
    physics_students[0]->setGraduationSemester(Semester::Spring);
    physics_students[0]->setDegreeLevel(DegreeLevel::Undergrad);
    physics_students[0]->setConcentration(PhysicsConcentration::Biophysics);

    physics_students[1]->setName("Raj", "Patel");
    physics_students[1]->setGPA(3.6);
    physics_students[1]->setEnrolledYear(2023);
    physics_students[1]->setEnrolledSemester(Semester::Fall);
    physics_students[1]->setGraduationYear(2027);
    physics_students[1]->setGraduationSemester(Semester::Spring);
    physics_students[1]->setDegreeLevel(DegreeLevel::Undergrad);
    physics_students[1]->setConcentration(PhysicsConcentration::EarthAndPlanetarySciences);

    physics_students[2]->setName("Hannah", "Weiss");
    physics_students[2]->setGPA("3.92");
    physics_students[2]->setEnrolledYear(2024);
    physics_students[2]->setEnrolledSemester(Semester::Spring);
    physics_students[2]->setGraduationYear(2028);
    physics_students[2]->setGraduationSemester(Semester::Spring);
    physics_students[2]->setDegreeLevel(DegreeLevel::Grad);
    physics_students[2]->setConcentration(PhysicsConcentration::Biophysics);

    physics_students[3]->setName("Omar", "Haddad");
    physics_students[3]->setGPA(2.9);
    physics_students[3]->setEnrolledYear(2021);
    physics_students[3]->setEnrolledSemester(Semester::Fall);
    physics_students[3]->setGraduationYear(2025);
    physics_students[3]->setGraduationSemester(Semester::Fall);
    physics_students[3]->setDegreeLevel(DegreeLevel::Undergrad);
    physics_students[3]->setConcentration(PhysicsConcentration::EarthAndPlanetarySciences);

    physics_students[4]->setName("Yuki", "Tanaka");
    physics_students[4]->setGPA(3.75);
    physics_students[4]->setEnrolledYear(2025);
    physics_students[4]->setEnrolledSemester(Semester::Fall);
    physics_students[4]->setGraduationYear(2030);
    physics_students[4]->setGraduationSemester(Semester::Spring);
    physics_students[4]->setDegreeLevel(DegreeLevel::Grad);
    physics_students[4]->setConcentration(PhysicsConcentration::Biophysics);

    // ---- Write everything to a single file ----------------------------------
    std::ofstream outfile("student_info.dat", std::ios::out);
    if (!outfile.is_open())
    {
        std::cerr << "Error: could not open student_info.dat for writing\n";
        return 1;
    }

    outfile << "===== ART STUDENTS =====\n\n";
    for (size_t i = 0; i < art_students.size(); i++)
    {
        art_students[i]->write(outfile);
        outfile << "\n";
    }

    outfile << "===== PHYSICS STUDENTS =====\n\n";
    for (size_t i = 0; i < physics_students.size(); i++)
    {
        physics_students[i]->write(outfile);
        outfile << "\n";
    }
    outfile.close();

    // ---- Free all heap memory (every new needs a matching delete) -----------
    for (size_t i = 0; i < art_students.size(); i++)     delete art_students[i];
    for (size_t i = 0; i < physics_students.size(); i++) delete physics_students[i];
    art_students.clear();
    physics_students.clear();

    std::cout << "Wrote student information to student_info.dat\n";
    return 0;
}

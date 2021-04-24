# Alanté "Alan" D. Powell
# Spring 2021 - Programming Language Concepts
# Exam 2 - Question 8 - Q8_Python.py

# Declaration of Global Variable
student_name = "Alan"
print(f"Global Variable: {student_name}.")

def subprogram_one():
    student_GPA = 3.0
    student_major = "Computer Science"

    print(f"{student_name} is a {student_major} student.")
    print(f"{student_name} has a {student_gpa} GPA.")

    def subprogram_two():
        global student_name

        print(f"{student_name} got married.")
        student_name = "Alan Powell"
        print(f"New name: {student_name}.")
        student_college = "College of Arts & Sciences"

        def subprogram_three():
            print("Level 3")
            print("----------------------")
            nonlocal student_college
            student_college = "Arts & Sciences"

            print(f"Student current attends: {student_college}.")

            student_name = "Alante D. Powell"
            print(f"For graduation, the student's name is: {student_name}.")
            print("----------------------")
        subprogram_three()
    subprogram_two()
subprogram_one()

print(f"After completion, the value of the local variable (student_name) is: {student_name}.")
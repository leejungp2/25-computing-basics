class SNUMember:
    def __init__(self, name, age, email):
        self.name = name
        self.age = age
        self.email = email

class Student(SNUMember):
    def __init__(self, name, age, email):
        super().__init__(name, age, email)
        self.position = 'student'
        self.grades = {}

class Professor(SNUMember):
    def __init__(self, name, age, email):
        super().__init__(name, age, email)
        self.position = 'professor'

class GSDSStudent(Student):
    def __init__(self, name, age, email, advisor):
        super().__init__(name, age, email)
        self.position = 'gsds student'
        self.advisor = advisor

class Course:
    def __init__(self, code, title, max_capacity):
        self.code = code
        self.title = title
        self.max_capacity = max_capacity
        self.num_students = 0
        self.students_enrolled = set()

    def enroll_student(self, student:Student):
        if student in self.students_enrolled:
            return False
        if self.num_students < self.max_capacity:
            self.students_enrolled.add(student)
            self.num_students += 1
            return True
        return False

class GSDSCourse(Course):
    def __init__(self, code, title, gsds_capacity, other_capacity):
        super().__init__(code, title, gsds_capacity + other_capacity)
        self.gsds_capacity = gsds_capacity
        self.other_capacity = other_capacity
        self.num_gsds_student = 0
        self.num_other_student = 0

    def enroll_student(self, student:Student):
        if student in self.students_enrolled:
            return False

        # check if student is GSDSStudent
        if isinstance(student, GSDSStudent):
            if self.num_gsds_student < self.gsds_capacity:
                self.students_enrolled.add(student)
                self.num_gsds_student += 1
                self.num_students += 1
                return True
        else:
            if self.num_other_student < self.other_capacity:
                self.students_enrolled.add(student)
                self.num_other_student += 1
                self.num_students += 1
                return True
        return False

class SNUManagementSystem:
    def __init__(self):
        self.students = []
        self.professors = []
        self.courses = []

    def get_class_name(self, value):
        return value.__class__.__name__

    def find_student_by_name(self, name:str):
        for student in self.students:
            if student.name == name:
                return student
        return None
    
    def find_course_by_code(self, code:str):
        for course in self.courses:
            if course.code == code:
                return course
        return None
    
    def find_professor_by_name(self, name:str):
        for professor in self.professors:
            if professor.name == name:
                return professor
        return None

    def register_professor(self, name:str, age:int, email:str):
        professor = Professor(name, age, email)
        self.professors.append(professor)
        return professor

    def register_student(self, name:str, age:int, email:str, advisor_name=None):
        if advisor_name:
            advisor = self.find_professor_by_name(advisor_name)
            student = GSDSStudent(name, age, email, advisor)
        else:
            student = Student(name, age, email)
        self.students.append(student)
        return student

    def offer_course(self, code:str, title:str, capacity:int, capacity_2=None):
        if capacity_2 is not None:
            # GSDS Course
            course = GSDSCourse(code, title, capacity, capacity_2)
        else:
            # Regular Course
            course = Course(code, title, capacity)
        self.courses.append(course)
        return course
    
    def enroll_course(self, student_name:str, course_code:str):
        student = self.find_student_by_name(student_name)
        course = self.find_course_by_code(course_code)
        
        if student and course:
            return course.enroll_student(student)
        return False

    def assign_grade(self, student_name:str, course_code:str, grade:str):
        student = self.find_student_by_name(student_name)
        course = self.find_course_by_code(course_code)
        
        # assign grade if enrolled
        if student and course and student in course.students_enrolled:
            student.grades[course_code] = grade
            return True
        return False

    def generate_student_report(self, student_name:str)->str:
        student = self.find_student_by_name(student_name)
        if not student:
            return ""
        
        # Check if GSDS student
        if isinstance(student, GSDSStudent):
            report = f"Report for {student.position} {student.name} ({student.age}, {student.email}, advisor: {student.advisor.position} {student.advisor.name})\n"
        else:
            report = f"Report for {student.position} {student.name} ({student.age}, {student.email})\n"
        
        # Add grades
        for course_code, grade in student.grades.items():
            report += f"\t{course_code}: {grade}\n"
        
        return report

    def generate_course_report(self, course_code:str)->str:
        course = self.find_course_by_code(course_code)
        if not course:
            return ""
        
        # Check if GSDS course
        if isinstance(course, GSDSCourse):
            report = f"Report for {course.code} ({course.title}, {course.num_gsds_student}/{course.gsds_capacity}, {course.num_other_student}/{course.other_capacity})\n"
        else:
            report = f"Report for {course.code} ({course.title}, {course.num_students}/{course.max_capacity})\n"
        
        # Add enrolled students
        if course.students_enrolled:
            student_names = sorted([s.name for s in course.students_enrolled])
            report += f"\tStudents enrolled in {course.code}: {', '.join(student_names)}\n"
        else:
            report += f"\tNo students found for {course.code}\n"
        
        return report
    
################################################################################################

def load_grades_from_file(sms:SNUManagementSystem, file_path:str):
    with open(file_path, 'r') as f:
        for line in f:
            line = line.strip()
            if line:
                parts = line.split(',')
                student_name = parts[0]
                course_code = parts[1]
                grade = parts[2]
                sms.assign_grade(student_name, course_code, grade)
   

def load_students_from_file(sms:SNUManagementSystem, file_path:str):
    with open(file_path, 'r') as f:
        for line in f:
            line = line.strip()
            if line:
                parts = line.split(',')
                name = parts[0]
                age = int(parts[1])
                email = parts[2]
                advisor_name = parts[3] if len(parts) > 3 else None
                sms.register_student(name, age, email, advisor_name)

def load_professors_from_file(sms:SNUManagementSystem, file_path:str):
    with open(file_path, 'r') as f:
        for line in f:
            line = line.strip()
            if line:
                parts = line.split(',')
                name = parts[0]
                age = int(parts[1])
                email = parts[2]
                sms.register_professor(name, age, email)
                
def load_courses_from_file(sms:SNUManagementSystem, file_path:str):
    with open(file_path, 'r') as f:
        for line in f:
            line = line.strip()
            if line:
                parts = line.split(',')
                code = parts[0]
                title = parts[1]
                capacity = int(parts[2])
                capacity_2 = int(parts[3]) if len(parts) > 3 else None
                sms.offer_course(code, title, capacity, capacity_2)

def load_enrollment_history_from_file(sms:SNUManagementSystem, file_path:str):
    with open(file_path, 'r') as f:
        for line in f:
            line = line.strip()
            if line:
                parts = line.split(',')
                student_name = parts[0]
                course_code = parts[1]
                sms.enroll_course(student_name, course_code)

def save_student_report_to_file(sms:SNUManagementSystem, student_name:str, file_path:str):
    report = sms.generate_student_report(student_name)
    with open(file_path, 'a') as f:
        f.write(report)

def save_course_report_to_file(sms:SNUManagementSystem, course_code:str, file_path:str):
    report = sms.generate_course_report(course_code)
    with open(file_path, 'a') as f:
        f.write(report)


################################Don't touch below code##############################################

sms = SNUManagementSystem()

# 파일 경로(file path)는 수정 가능
load_professors_from_file(sms, 'dataset/professors.txt')
load_students_from_file(sms, 'dataset/students.txt')
load_courses_from_file(sms, 'dataset/courses.txt')
load_enrollment_history_from_file(sms, 'dataset/enroll_history.txt')
load_grades_from_file(sms, 'dataset/grade_error.txt')

student_report_file = 'students_report.txt'
course_report_file = 'courses_report.txt'

for student in sms.students:
    save_student_report_to_file(sms, student.name, student_report_file)

for course in sms.courses:
    save_course_report_to_file(sms, course.code, course_report_file)

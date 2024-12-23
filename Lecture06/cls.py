class Student():
    def __init__(self, name, idnumber):
        self.name = name
        self.idnumber = idnumber

    def change_id(self,idnumber):
        self.idnumber = idnumber

    def print_student(self):
        print(self.name, self.idnumber, sep=(" / ") )


student = Student("Furkan", 10)
student.print_student()
student.change_id(21)
student.print_student()
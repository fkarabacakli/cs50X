import csv
from cs50 import SQL

def main():
    students = []
    
    with open("/Users/halilfurkankarabacakli/Desktop/CS50/CS50X/Lecture07_Assaigment/prophecy/students.csv", 'r') as read_file:
        reader = csv.DictReader(read_file)
        for row in reader:
            students.append({"id":row['id'],"student_name":row['student_name'],"house":row['house'],"head":row['head']})
    houses = {}
    for student in students:
        if student['house'] not in houses:
            houses.update({student['house']:student['head']})

    db = SQL("sqlite:///roster.db")
    student_house = "Slytherin"
    
    for house in houses:
        db.execute("INSERT INTO houses (house, head) VALUES (?,?)", house, houses[house])
    
    for student in students:
        db.execute("INSERT INTO student (student_name) VALUES (?)", (student['student_name']))
        
        student_id = db.execute("SELECT id from student WHERE student_name = ? ", student['student_name'])
        student_id = student_id[0]['id']
        
        house_number = db.execute("SELECT id from houses WHERE house = ? ", student['house'])
        house_number = house_number[0]['id']

        db.execute("INSERT INTO main (id,house) VALUES (?,?)", student_id,house_number)

    
          






if __name__ == "__main__":
    main()
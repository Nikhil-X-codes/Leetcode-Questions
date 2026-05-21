# Write your MySQL query statement below

SELECT s.student_id,
       s.student_name,
       sub.subject_name,
       COUNT(e.subject_name) AS attended_exams
FROM Students s
CROSS JOIN Subjects sub

left join Examinations e
on s.student_id = e.student_id
AND sub.subject_name = e.subject_name

GROUP BY s.student_id,
         s.student_name,
         sub.subject_name

order by student_id, subject_name;




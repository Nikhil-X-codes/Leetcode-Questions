# Write your MySQL query statement below

select e2.name from Employee e1
JOIN Employee e2 on e1.managerId=
e2.id group by e1.managerId
HAVING COUNT(*) >= 5;

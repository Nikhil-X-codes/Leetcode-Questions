# Write your MySQL query statement below

select id,
case when id % 2 = 1 then COALESCE(Lead(student) over (order by id),student)
else lag(student) over (order by id)
end as student
from Seat
order by id

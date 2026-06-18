# Write your MySQL query statement below


select id,
case 
when p_id is NULL then 'Root'

when id in (
SELECT p_id
               FROM Tree
               WHERE p_id IS NOT NULL
) then 'Inner'

else 'Leaf'
END as type 
from Tree

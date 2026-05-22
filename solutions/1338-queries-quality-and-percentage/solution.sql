
select query_name,
Round(sum(rating/position) / count(*),2) as quality,
   ROUND(
        SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) * 100 / COUNT(*),
        2
    )  as poor_query_percentage
from Queries
group by query_name

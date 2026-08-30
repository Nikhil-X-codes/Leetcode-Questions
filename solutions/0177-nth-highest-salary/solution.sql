CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
     
        SELECT salary
        FROM (

            SELECT salary,
                   DENSE_RANK() OVER (
                       ORDER BY salary DESC
                   ) AS `rank`
            FROM Employee
        ) 
        AS getNthHighestSalary
        WHERE `rank` = N
        LIMIT 1

  );
END

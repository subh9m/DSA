/* Write your T-SQL query statement below */
SELECT e1.name, b1.bonus
FROM Employee AS e1
FULL OUTER JOIN Bonus AS b1
    ON e1.empId = b1.empId
    WHERE b1.bonus < 1000 OR b1.bonus IS NULL;
    
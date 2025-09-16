/* Write your T-SQL query statement below */
SELECT E1.unique_id, E.name 
FROM Employees AS E
LEFT JOIN EmployeeUNI AS E1
ON
E.id = E1.id
CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  RETURN QUERY (
    -- Write your PostgreSQL query statement below.
    select e1.salary
    from 
    Employee e1
    where (select count(distinct e2.salary)
           from Employee as e2
           where e2.salary > e1.salary)
    =N - 1
    limit 1   
  );
END;
$$ LANGUAGE plpgsql;
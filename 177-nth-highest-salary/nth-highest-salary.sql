CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (getNthHighestSalary INT) AS $$
BEGIN
  RETURN QUERY (
    -- Write your PostgreSQL query statement below.
    SELECT e1.salary 
    from Employee e1
    where(
        select count(distinct e2.salary)
        from Employee e2
        where e2.salary > e1.salary
    ) = N-1
    LIMIT 1
      
  );
END;
$$ LANGUAGE plpgsql;
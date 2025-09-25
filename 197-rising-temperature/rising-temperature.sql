/* Write your T-SQL query statement below */
select W1.id
from Weather as W1
join 
Weather as W2
on 
datediff(day, W2.recordDate, W1.recordDate) = 1
where W1.temperature > W2.temperature
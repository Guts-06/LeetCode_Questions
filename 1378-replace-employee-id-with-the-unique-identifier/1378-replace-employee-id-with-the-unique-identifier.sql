# Write your MySQL query statement below
SELECT eu.unique_id as unique_id , e.name as name from Employees as e 
Left JOin EmployeeUNI as eu
on e.id=eu.id;

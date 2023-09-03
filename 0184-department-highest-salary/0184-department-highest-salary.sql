# Write your MySQL query statement below


select d.name as Department, e.name as Employee, e.salary as Salary from Employee e join Department d on e.departmentId = d.id
where e.salary = (select max(salary) from Employee e1 group by e1.departmentId  having e1.departmentId = e.departmentId);

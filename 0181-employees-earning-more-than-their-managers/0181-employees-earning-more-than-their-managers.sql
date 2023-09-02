# Write your MySQL query statement below
select c.name as employee from employee as c inner join employee as d on c.managerid=d.id where c.salary>d.salary;
# Write your MySQL query statement below
select c.lastname, c.firstname,d.city,d.state from person as c left join address as d on c.personid=d.personid;

# Write your MySQL query statement below
select c.year, c.price,d.product_name from sales as c inner join product as d on c.product_id=d.product_id;
-- select *
-- from customers
-- limit 6 ,3;
-- page 1 1 to 3
-- page 2 4 to 6
-- page 6 7 to 9

-- get top 3 loyal customers 
select *
from customers
order by points desc
limit 3;

select first_name , last_name , shipped_date , o.customer_id 
from orders o  
join customers c
on o.customer_id= c.customer_id;

select order_id,o.product_id, quantity , o.unit_price
-- unit price is taken from the orders table bcoz that is the price at the time of placing the order wherease the unitprice in products tables is the current price rigth now 
from order_items o
join products p
on o.product_id= p.product_id;


select e.employee_id , e.first_name ,m.first_name as manager 
from employees e
join employees m
on e.reports_to = m.employee_id;

use sql_store;

select o.order_id, o.order_date,c.first_name, c.last_name , os.name
from orders o
join customers c
on o.customer_id=c.customer_id
join order_statuses os
on o.status=os.order_status_id

use sql_invoicing
select p.payment_id ,c.name,p.invoice_id, p.date , p.amount , pm.name
from payments p
join payment_methods pm
on p.payment_method = pm.payment_method_id
join clients c
on c.client_id = p.client_id

use sql_store

select *
from order_items oi
join order_item_notes oin
on oi.order_id=oin.order_id and oi.product_id = oin.product_id;


select *
from orders o , customers c
where o.order_id = c.customer_id;


select c.customer_id,c.first_name , o.order_id,sh.name
from customers c
left join orders o -- left outer join we get all the customers iirespectove of they have nan order or not
on c.customer_id=o.customer_id  
left join shippers sh-- we get all the orders irrespective of if they have a shipper or not 
on o.shipper_id = sh.shipper_id; -- inner join
order by c.order_id;


select p.product_id,p.name,oi.quantity
from products p
left join order_items oi
on p.product_id = oi.product_id

select o.order_date , o.order_id ,c.first_name,sh.name ,os.name
from orders o
left join order_statuses os
on os.order_status_id=o.status
left join customers c
on o.customer_id = c.customer_id
left join shippers sh
on  sh.shipper_id=o.shipper_id 
order by sh.name

use sql_hr

select  e.employee_id , e.first_name, m.first_name as manager
from employees e
left join employees m 
-- n e.reports_to=m.employee_id
use sql_store

select o.order_id , c.first_name ,sh.name as shipper
from orders o
join customers c
using (customer_id)
left join shippers sh
using(shipper_id)

select *
from order_items oi
left join order_item_notes oin
using (product_id,  order_id)
use sql_invoicing

select p.date , c.name , p.amount ,pm.name
from payments p
join payment_methods pm
on p.payment_method= pm.payment_method_id
join clients c
using (client_id) 

use sql_store

select o.order_id , c.first_name
from orders o
natural join customers
ORDER BY order_id


select  C.FIRST_NAME AS CUSTOMER ,p.name as product 
from customers c
cross join products p
order by c.first_name 

select p.name as product , sh.name as shipper
from shippers  sh
cross join products p
order by sh.name

select order_id, order_date ,'Active' as status
from orders
where order_date >="2019-01-01"
union
select order_id, order_date ,'Archive' as status
from orders
where order_date <"2019-01-01"

SELECT FIRST_NAME
FROM customers
union
select name
from shippers

select customer_id , first_name , points ,'bronze' as type
from customers  
where points<2000
union
select customer_id , first_name , points ,'silver' as type
from customers  
where points between 2000 and 3000
union
select customer_id , first_name , points ,'gold' as type
from customers  
where points>3000
order by first_name

INSERT INTO CUSTOMERS(first_name , last_name ,birth_date , address, city , state)
values('aparna','mane','1998-06-12','beverly hill','city','ca');

insert into shippers(name)
values('shipper1'),
       ('shipper2'),
	   ('shipper3')
       
insert into products(name,quantity_in_stock,unit_price)
values('x',45, 9.24),
	   ('y',48, 3.27),
      ('z',90, 8.21)
      
insert into orders(customer_id, order_date, status)
values (1,'2019-01-01',1);
insert into order_items
values(last_insert_id(),1,1,2.95),
       (last_insert_id(),2,1,3.95)
       


      
      select *
      from order_items
      order by product_id


create table orders_archived as
select * from orders

insert into orders_archived 
select *
from orders
where order_date <'2019-01-01'
use sql_invoicing
create invoices_archived as
select invoice_id ,client_id,payment_total
from invoices
where payment_date!=NULL

select name,c.client_id
from clients c
right join invoices i
on i.client_id= c.client_id


create table invoices_archived as
select i.invoice_id , i.number ,c.name as client , i.invoice_date ,payment_date , due_date
from invoices i
join clients c
using(client_id)
where payment_date is not NULL

UPDATE INVOICES
SET PAYMENT_TOTAL =invoice_total *0.5, PAYMENT_DATE =due_date
WHERE client_ID =3
use sql_store

update customers
set points= points+50
where birth_date < '1990-01-01'










create database hospitalmgm ;

\c hospitalmgm

create table patient_table
( pid int primary key,
	pat_name varchar,
  bed_no int,
  doc_id int,
  admit_date date,
  dis_date date ,
  treat_type varchar
  
  );

create table doctor_details
(doc_name varchar,
	doc_id int  primary key,
 specialist varchar
 );

create table Hospital 
(
	name varchar,
 address varchar,
 email varchar
);

create table beds 
( bed_no int,
	pid int,
  admit_date date,
  dis_date date
  
);

create table days
(
	pid int,
 pat_name varchar,
 admit_date date,
 dis_date date
);

create table payment
(
	pat_id int,
 pat_name varchar,
 medicine_chrg varchar,
 doctor_chrg varchar,
 maintain_chrg varchar,
 payment_id varchar,
 total int
);

create table dieses
(
	sno int ,
  major varchar
 
);

create table occupies 
(
	pid int ,
 	pat_name varchar,
	bed_no int, 
	admit_date date
 	
);

create table outtype
(
	pid int,
 admit_date date
);

create table intype 
(
	pid int,
 bed_no int,
 admit_date date,
 dis_date date
);

create table avail_beds
( 
	bed_no int ,
    pid int ,
    admit_date date ,
    dis_date date 
);
-------data for patient_table

insert into patient_table values ( '1001','surendar','11','111','2022-07-20','2022-08-10','IN'),
( '1002','emmawatson','12','116','2022-07-21','2022-08-10','IN'),
( '1003','emma stone','13','115','2022-07-21','2022-08-10','IN'),
( '1004','billie ellish','14','112','2022-07-23','2022-08-10','IN'),
( '1005','gal gadot','15','114','2022-07-23','2022-08-10','IN'),
( '1006','john','16','113','2022-07-25','2022-08-10','IN'),
('1007','chandru',null,'114','2022-07-26','2022-08-10','OUT'),
('1008','masthan',null,'115','2022-07-27','2022-08-10','OUT'),
('1009','srinath',null,'116','2022-07-27','2022-08-10','OUT');
--------data for doctor details 
 insert into Doctor_details values('steve','111','heart'),('bruce','112','ent'),('tony','113','eye'),
 ('nick','114','general'),('jhony','115','general'),('milburn','116','general');
 
 
 --------data for hospital
 
 insert into Hospital values('ukhospital','chennai','ukhospital@email.com');
 
 ------data for beds
 
 insert into beds values ('11','1001','2022-07-20','2022-08-10'),
 ('12','1002','2022-07-21','2022-08-10'),
 ('13','1003','2022-07-21','2022-08-10'),
 ('14','1004','2022-07-23','2022-08-10'),
 ('15','1005','2022-07-23','2022-08-10'),
 ('16','1006','2022-07-25','2022-08-10'),
 (null,'1007','2022-07-26','2022-08-10'),
 (null,'1008','2022-07-27','2022-08-10'),
 (null,'1009','2022-07-27','2022-08-10'),
 ('17',null,null,null),
 ('18',null,null,null);
 
 
 ------data for days
 
 insert into days values ('1001','surendar','2022-07-20','2022-08-10'),
 ('1002','emmawatson','2022-07-21','2022-08-10'),
 ('1003','emma stone','2022-07-21','2022-08-10'),
 ('1004','billie ellish','2022-07-23','2022-08-10'),
 ('1005','gal gadot','2022-07-23','2022-08-10'),
 ('1006','john','2022-07-25','2022-08-10'),
 ('1007','chandru','2022-07-26','2022-08-10'),
 ('1008','masthan','2022-07-27','2022-08-10'),
 ('1009','srinath','2022-07-27','2022-08-10');
 
 ------data for payment
 
 insert into  payment values ('1015','kathir','3000','500','50','12022020','3550'),
 ('1016','sakthi','5000','500','100','12022021','5600');
 
 
 ------data for dieses
 
 insert into dieses values ('1','heart'),('2','ent'),('3','eye');
 
 ------data for occupies 
 
 insert into occupies values ( '1001','surendar','11','2022-07-20'),
 ( '1002','emmawatson','12','2022-07-21'),
 ( '1003','emma stone','13','2022-07-21'),
 ( '1004','billie ellish','14','2022-07-23'),
 ( '1005','gal gadot','15','2022-07-23'),
 ( '1006','john','16','2022-07-25');
 
--------data for outytpe

insert into outtype 
values ('1007','2022-07-26'),
 ('1008','2022-07-27'),
 ('1009','2022-07-27');
 
-------data for intype 

insert into intype values
( '1001','11','2022-07-20','2022-08-10'),
( '1002','12','2022-07-21','2022-08-10'),
( '1003','13','2022-07-21','2022-08-10'),
( '1004','14','2022-07-23','2022-08-10'),
( '1005','15','2022-07-23','2022-08-10'),
( '1006','16','2022-07-25','2022-08-10');


-----data for avail_beds

insert into avail_beds
values ('17',null,null,null),('18',null ,null ,null);

---------
---------  queries
---------


	-----finding which all are beds free -----
 
 	select b.bed_no,b.pid,b.admit_date,a.bed_no from beds b   join avail_beds a on b.bed_no = a.bed_no ;
	
	
	--------showing all doctor_details-------
	
	
	select * from doctor_details;
	
	
	------finding who all are there in hospital more than 5 days------
	
	select dis_date::date - admit_date::date as date  from patient_table;
	
	
	------showing all patient details along with bed numbers-------
	
	select p.pid,p.pat_name,p.admit_date,p.bed_no from patient_table p join beds b on p.pid=b.pid;
	
	
	-------show all doctor details along with the number of patients--------
	
	
	select d.doc_name,d.doc_id, p.pid,p.pat_name,p.doc_id from doctor_details d join patient_table p on d.doc_id =p.doc_id  order by p.doc_id;
	
	
	-------
	--------  functions
	-------
	
	
	
	

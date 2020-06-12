--CREATE TABLE STUDENTS(
   S_ID VARCHAR2(10),
    S_PWD VARCHAR2(30),
    S_MAJOR VARCHAR2(30),
    S_NAME    VARCHAR2(13),
    S_ADDR  VARCHAR2(20),
    S_UNIT  NUMBER(2),
    S_GRADE NUMBER(1),
   CONSTRAINT students_pk PRIMARY KEY(S_ID)
);

INSERT INTO STUDENTS VALUES('11',123456,'test','abcd','test@',18,4);
INSERT INTO STUDENTS VALUES('22',123456,'미디어학부','noon','noon@naver.com',21,4);


CREATE TABLE professor(
   P_ID NUMBER(3),
    NAME VARCHAR2(10),
    UNIV VARCHAR2(10),
    MAJOR VARCHAR2(20),
   CONSTRAINT prof_pk PRIMARY KEY(p_id)
);
insert into professor values (101,'쿠퍼 소피','숙명','교양학부');
insert into professor values (301,'서희정','숙명','미디어학부');
insert into professor values (207,'유석종','숙명','컴과');
insert into professor values (302,'김보람','숙명','식품영양학과');
insert into professor values (303,'정홍','숙명','나노물리학과');
insert into professor values (111,'test','숙명','major');
insert into professor values (205,'박숙영','숙명','컴과');
insert into professor values (202,'박영훈','숙명','컴과');
insert into professor values (201,'심준호','숙명','컴과');
insert into professor values (204,'이광수','숙명','컴과');

CREATE TABLE COURSE(
   c_year NUMBER(4) NOT NULL,
   c_semes NUMBER(1) NOT NULL,
   p_id NUMBER(3),
   c_id NUMBER(8),
   c_id_no NUMBER(1),
   c_name VARCHAR2(30),
   c_unit NUMBER(1),
   c_personnel NUMBER(3),
   c_remain NUMBER(3),
   c_type VARCHAR2(9),
   c_major VARCHAR2(30),
   c_language VARCHAR2(9),
   CONSTRAINT course_pk PRIMARY KEY (c_id,c_id_no),
   CONSTRAINT course_fk  FOREIGN KEY (p_id) REFERENCES Professor (p_id)
);
INSERT INTO COURSE VALUES (2020,1,101,21000083,2,'영어쓰기와읽기',3,20,20,'교필','교양학부','영어');
INSERT INTO COURSE VALUES (2020,1,301,21002313,1,'매스미디어와사회',3,25,25,'교핵','미디어학부','');
INSERT INTO COURSE VALUES (2020,1,207,21000540,2,'자료구조',3,35,35,'전필','컴퓨터과학부','영어');
INSERT INTO COURSE VALUES (2020,1,302,21000803,1,'생활속식품이야기',3,55,55,'교핵','식품영양학과','');
INSERT INTO COURSE VALUES (2020,1,303,21000428,1,'인간과우주',3,200,200,'교핵','나노물리학과','');
INSERT INTO COURSE VALUES (2020,2,205,21000557,2,'자바프로그래밍',3,35,35,'전선','컴퓨터과학부','');
INSERT INTO COURSE VALUES (2020,2,202,21000558,2,'네트워크보안',3,35,35,'전선','컴퓨터과학부','');
INSERT INTO COURSE VALUES (2020,2,201,21003183,2,'데베설',3,35,35,'전선','컴퓨터과학부','');
INSERT INTO COURSE VALUES (2020,1,201,21003946,1,'컴퓨터과학의이해',3,55,55,'교핵','컴퓨터과학부','');
INSERT INTO COURSE VALUES (2020,2,204,21002144,1,'프로그래밍개론1',3,55,55,'교핵','컴퓨터과학부','');


CReATE TABLE CLASS(
   p_id NUMBER(3),
   c_id NUMBER(8),
   c_id_no NUMBER(1),
   c_where VARCHAR2(30),
   CONSTRAINT class_pk PRIMARY KEY (p_id,c_id,c_id_no),
   CONSTRAINT class_fk_prof FOREIGN KEY(p_id) REFERENCES professor (p_id),
   CONSTRAINT class_fk_course FOREIGN KEY (c_id,c_id_no) REFERENCES course(c_id,c_id_no)
);

insert into class values (301,21002313,1,'명신관401');
insert into class values (207,21000540,2,'창학B101');
insert into class values (302,21000803,1,'과학관201');
insert into class values (303,21000428,1,'명신관301');
insert into class values (205,21000557,2,'명신관305');
insert into class values (202,21000558,2,'진리관401');
insert into class values (201,21003946,1,'명신관402');
insert into class values (204,21002144,1,'명신관403');
insert into class values (201,21003183,2,'명신관404');

create table class_time(
  seq number(3),
  c_id number(8),
  c_id_no number(1),
  c_day varchar(3),
  c_stime varchar2(5),
  c_etime varchar2(5),
  constraint time_pk primary key (seq),
  constraint time_fk_course foreign key (c_id,c_id_no) REFERENCES course(c_id,c_id_no)
);

insert into class_time values (1,21002313,1,'화','09:00','10:15');
insert into class_time values (3,21000540,2,'화','09:00','10:15');
insert into class_time values (5,21000803,1,'월','10:30','11:15');
insert into class_time values (7,21000428,1,'월','10:30','11:15');
insert into class_time values (9,21000557','2',월','11:30','12:45');
insert into class_time values (11,21000558,2,'화','13:00','14:15');
insert into class_time values (13,21003946,1,'화','14:30','15:45');
insert into class_time values (15,21002144,1,'월','14:30','15:45');
insert into class_time values (17,21003183,2,'수','09:00','12:45');
insert into class_time values (2,21002313,1,'목','09:00','10:15');
insert into class_time values (4,21000540,2,'목','09:00','10:15');
insert into class_time values (6,21000803,1,'수','10:30','11:15');
insert into class_time values (8,21000428,1,'수','10:30','11:15');
insert into class_time values (10,21000557','2',수','11:30','12:45');
insert into class_time values (12,21000558,2,'목','13:00','14:15');
insert into class_time values (14,21003946,1,'목','14:30','15:45');
insert into class_time values (16,21002144,1,'수','14:30','15:45');



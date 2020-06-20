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

INSERT INTO STUDENTS VALUES('1510188',123456,'컴퓨터과학부','이지혜','hello@naver.com',21,4);
INSERT INTO STUDENTS VALUES('22',123456,'미디어학부','기니디','noon@gmail.com',21,4);
INSERT INTO STUDENTS VALUES('33',123456,'한국어문학부','고노도','gonodo@naver.com',21,1);
INSERT INTO STUDENTS VALUES('44',123456,'체육학과','구누두','gunudu@sm.ac.kr',21,2);
INSERT INTO STUDENTS VALUES('55',123456,'법학과','그느드','geuneudeu@naver.com',24,3);
INSERT INTO STUDENTS VALUES('66',123456,'나노물리학과','거너더','myemail@naver.com',24,4);

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
insert into professor values (102,'고대선','숙명','체육학과');
insert into professor values (103,'이욱한','숙명','교양학부');

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
INSERT INTO COURSE VALUES (2020,1,101,21000083,1,'영어쓰기와읽기',3,5,5,'교필','교양학부','영어');
INSERT INTO COURSE VALUES (2020,1,301,21002313,1,'매스미디어와사회',3,5,5,'교핵','미디어학부','');
INSERT INTO COURSE VALUES (2020,1,207,21000540,2,'자료구조',3,5,5,'전필','컴퓨터과학부','영어');
INSERT INTO COURSE VALUES (2020,1,207,21000540,1,'자료구조',3,5,5,'전필','컴퓨터과학부','');
INSERT INTO COURSE VALUES (2020,1,302,21000803,1,'생활속식품이야기',3,5,5,'교핵','식품영양학과','');
INSERT INTO COURSE VALUES (2020,1,303,21000428,1,'인간과우주',3,5,5,'교핵','나노물리학과','');
INSERT INTO COURSE VALUES (2020,2,205,21000557,1,'자바프로그래밍',3,5,5,'전선','컴퓨터과학부','');
INSERT INTO COURSE VALUES (2020,2,202,21000558,1,'네트워크보안',3,5,5,'전선','컴퓨터과학부','');
INSERT INTO COURSE VALUES (2020,2,201,21003183,1,'데이터베이스프로그래밍',3,5,5,'전선','컴퓨터과학부','');
INSERT INTO COURSE VALUES (2020,1,201,21003946,1,'컴퓨터과학의이해',3,5,5,'교핵','컴퓨터과학부','');
INSERT INTO COURSE VALUES (2020,2,204,21002144,1,'프로그래밍개론1',3,5,5,'교핵','컴퓨터과학부','');
INSERT INTO COURSE VALUES (2020,1,102,21001234,1,'교양풋살',2,5,5,'교일','체육학과','');
INSERT INTO COURSE VALUES (2020,1,102,21001234,2,'교양풋살',2,5,5,'교일','체육학과','');
INSERT INTO COURSE VALUES (2020,2,103,21001235,1,'철학개론',3,5,5,'교일','교양학부','');


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
insert into class values (207,21000540,1,'창학B101');
insert into class values (207,21000540,2,'창학B101');
insert into class values (302,21000803,1,'과학관201');
insert into class values (303,21000428,1,'');
insert into class values (205,21000557,1,'명신관305');
insert into class values (202,21000558,1,'진리관401');
insert into class values (201,21003946,1,'명신관402');
insert into class values (204,21002144,1,'명신관403');
insert into class values (201,21003183,1,'명신관404');
insert into class values (102,21001234,1,'다목적관102');
insert into class values (102,21001234,2,'다목적관102');
insert into class values (103,21001235,1,'순헌관506');
insert into class values (101,21000083,1,'명신관202');

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
insert into class_time values (5,21000803,1,'월','10:30','11:45');
insert into class_time values (7,21000428,1,'','','');
insert into class_time values (8,21000557,1,'월','11:30','12:45');
insert into class_time values (10,21000558,1,'화','13:00','14:15');
insert into class_time values (12,21003946,1,'화','14:30','15:45');
insert into class_time values (14,21002144,1,'월','14:30','15:45');
insert into class_time values (16,21003183,1,'수','09:00','12:45');
insert into class_time values (18,21000083,1,'화','11:00','12:15');
insert into class_time values (20,21001235,1,'','','');
insert into class_time values (21,21000540,1,'화','13:00','14:15');
insert into class_time values (19,21001234,1,'금','12:00','13:50');
insert into class_time values (2,21002313,1,'목','09:00','10:15');
insert into class_time values (4,21000540,2,'목','09:00','10:15');
insert into class_time values (6,21000803,1,'수','10:30','11:45');
insert into class_time values (9,21000557,1,'수','11:30','12:45');
insert into class_time values (11,21000558,1,'목','13:00','14:15');
insert into class_time values (13,21003946,1,'목','14:30','15:45');
insert into class_time values (15,21002144,1,'수','14:30','15:45');
insert into class_time values (17,21000083,1,'월','11:00','12:15');
insert into class_time values (23,21001234,2,'월','12:00','13:50');
insert into class_time values (22,21000540,1,'목','13:00','14:15');


CREATE TABLE ENROLL(
	s_id VARCHAR2(10),
	c_id NUMBER(8),
	c_id_no NUMBER(1),
	CONSTRAINT enroll_pk PRIMARY KEY (s_id,c_id,c_id_no),
	CONSTRAINT enroll_fk_students FOREIGN KEY (s_id) REFERENCES Students(s_id),
	CONSTRAINT enroll_fk_course FOREIGN KEY (c_id,c_id_no) REFERENCES course(c_id,c_id_no)
);

--20200618 조회 쿼리 수정 - 요일에 따라 여러row나오는 것 한줄로 합침
select COUR.C_YEAR,COUR.C_SEMES,COUR.C_ID,COUR.C_ID_NO,
COUR.C_NAME, COUR.C_UNIT, COUR.C_PERSONNEL, COUR.C_REMAIN, COUR.C_TYPE,
COUR.C_MAJOR, COUR.C_LANGUAGE,p.name
LISTAGG(t.C_DAY ||  t.C_STIME || '~' || t.C_ETIME || '(' || CL.C_WHERE || ')' ,', ')
  WITHIN GROUP(ORDER BY T.C_DAY DESC) AS "TIME"
from course cour left outer join class cl
on cour.p_id = cl.p_id and cour.c_id = cl.c_id and cour.c_id_no = cl.c_id_no
left outer join class_time t
on cour.c_id = t.c_id and cour.c_id_no = t.c_id_no
left outer join professor p on p.p_id = cour.p_id 
GROUP BY COUR.C_YEAR,COUR.C_SEMES,COUR.P_ID,COUR.C_ID,COUR.C_ID_NO,
COUR.C_NAME, COUR.C_UNIT, COUR.C_PERSONNEL, COUR.C_REMAIN, COUR.C_TYPE,
COUR.C_MAJOR, COUR.C_LANGUAGE, P.NAME;

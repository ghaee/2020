<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.*"  %>
<%@ page import="java.util.Calendar"  %>
<%@ page import="java.text.SimpleDateFormat" %>

<html><head><title>수강신청 입력</title></head>
<body>
<%@ include file="top.jsp" %>
<%   if (session_id==null) response.sendRedirect("login.jsp");  %>

<table width="75%" align="center" border>
<br>
<tr>
<th>학기년도</th><th>학기</th>
<th>과목번호</th><th>분반</th><th>과목명</th><th>학점</th><th>정원</th><th>여석</th>
<th>구분</th><th>주관학과</th><th>언어</th><th>교수</th><th>장소</th><th>요일</th><th>시작시간</th><th>종료시간</th>
<th>신청</th>
</tr>
<%
String dbdriver = "oracle.jdbc.driver.OracleDriver";
String dburl = "jdbc:oracle:thin:@localhost:1521:orcl";
String user = "db1510188";
String passwd = "test";

Connection myConn = null;      
Statement stmt = null;	
ResultSet rs = null;   
String mySQL = "";

/* java.text.SimpleDateFormat formatter = new java.text.SimpleDateFormat("yyyy-MM");
String today = formatter.format(new java.util.Date());
out.println(today); */
	
Calendar cal = Calendar.getInstance();
int year = cal.get(Calendar.YEAR);
int month =cal.get(Calendar.MONTH)+1;
int semes;
if(month <= 6){
	semes = 1;
}else{
	semes = 2;
}

try{
	Class.forName(dbdriver);
    myConn=DriverManager.getConnection(dburl, user, passwd);
    
  	//mySQL = "select * from course where c_semes = 1 and c_id not in (select c_id from enroll where s_id='" + session_id + "') order by c_id ASC";
  	mySQL = "select cour.*,p.name,cl.c_where, t.seq,t.c_day, t.c_stime,t.c_etime from course cour  left outer join class cl on cour.p_id = cl.p_id and cour.c_id = cl.c_id and cour.c_id_no = cl.c_id_no left outer join class_time t on cour.c_id = t.c_id and cour.c_id_no = t.c_id_no left outer join professor p on p.p_id = cour.p_id where c_year = "+year+" and c_semes = "+semes+" and cour.c_id not in (select e.c_id from enroll e where s_id='" + session_id + "') order by t.seq ASC";
  	stmt = myConn.createStatement();
  	rs = stmt.executeQuery(mySQL);
  	
  	if (rs.next()) {
  		do {	
  				String c_year = rs.getString("c_year");
  				String c_semes = rs.getString("c_semes");
  				String c_id = rs.getString("c_id");
  				int c_id_no = rs.getInt("c_id_no");			
  				String c_name = rs.getString("c_name");
  				int c_unit = rs.getInt("c_unit");		
  				int c_personnel = rs.getInt("c_personnel");
  				int c_remain = rs.getInt("c_remain");
  				String c_type = rs.getString("c_type");
  				String c_major = rs.getString("c_major");
  				String c_language = rs.getString("c_language");
  				String p_name = rs.getString("NAME");
  				String c_where = rs.getString("c_where");
  				String c_day = rs.getString("c_day");
  				String c_stime = rs.getString("c_stime");
  				String c_etime = rs.getString("c_etime");
  				if(c_language == null) c_language = "";
  				if(p_name == null) p_name = "미정";
  				if(c_where == null) c_where = "미정";
  				if(c_day == null) c_day = "미정";
  				if(c_stime == null) c_stime = "미정";
  				if(c_etime == null) c_etime = "미정";
  		%>
  		<tr>
  			<td align="center"><%= c_year %></td><td align="center"><%= c_semes %></td>
  		  <td align="center"><%= c_id %></td> <td align="center"><%= c_id_no %></td> 
  		  <td align="center"><%= c_name %></td><td align="center"><%= c_unit %></td>
  		  <td align="center"><%= c_personnel %></td><td align="center"><%= c_remain %></td>
  		  <td align="center"><%= c_type %></td><td align="center"><%= c_major %></td>
  		  <td align="center"><%= c_language %></td><td align="center"><%= p_name %></td>
  		  <td align="center"><%= c_where %></td><td align="center"><%= c_day %></td>
  		  <td align="center"><%= c_stime %></td><td align="center"><%= c_etime %></td>
  		  <td align="center"><a href="insert_verify.jsp?c_id=<%= c_id %>&c_id_no=<%= c_id_no %>&c_day=<%= c_day %>&c_stime=<%= c_stime %>&c_etime=<%= c_etime %>">신청</a></td>
  		</tr>
  		<%
  				}while(rs.next());
  		}
  			stmt.close();  myConn.close();
}catch(SQLException ex){
    System.err.println("SQLException: " + ex.getMessage());
}
%>
</table></body></html>
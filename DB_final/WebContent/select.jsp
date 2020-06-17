<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.*"  %>
<html><head><title>수강신청 조회</title></head>
<body>
<%@ include file="top.jsp" %>
<%   if (session_id==null) response.sendRedirect("login.jsp");  %>
<br>
<table width="75%" align="center" border>
<tr>
<th>과목명</th><th>교수</th><th>학점</th>
<th>장소</th><th>요일</th><th>시작시간</th><th>종료시간</th>
<th>수강 취소</th>
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

try{
	Class.forName(dbdriver);
    myConn=DriverManager.getConnection(dburl, user, passwd);
    
  	
  	mySQL="select distinct c.c_id,c.c_id_no, c.c_name,p.name,c.c_unit,cl.c_where,t.c_day, t.c_stime,t.c_etime from course c left outer join class cl on c.p_id = cl.p_id and c.c_id = cl.c_id and c.c_id_no = cl.c_id_no left outer join class_time t on c.c_id = t.c_id and c.c_id_no = t.c_id_no left outer join professor p on p.p_id = c.p_id where  c.c_id in (select e.c_id from enroll e where s_id='"+session_id+"')";
  	stmt = myConn.createStatement();
  	rs = stmt.executeQuery(mySQL);
  	if(rs.next()){
  		do {
  			String c_id = rs.getString("c_id");
			int c_id_no = rs.getInt("c_id_no");	
			String c_name = rs.getString("c_name");
			String p_name = rs.getString("NAME");
			int c_unit = rs.getInt("c_unit");		
			String c_where = rs.getString("c_where");
			String c_day = rs.getString("c_day");
			String c_stime = rs.getString("c_stime");
			String c_etime = rs.getString("c_etime");
			if(p_name == null) p_name = "미정";
			if(c_where == null) c_where = "미정";
			if(c_day == null) c_day = "미정";
			if(c_stime == null) c_stime = "미정";
			if(c_etime == null) c_etime = "미정";
		%>
		<tr>
			<td align="center"><%= c_name %></td>
		  <td align="center"><%= c_unit %></td><td align="center"><%= p_name %></td>
		  <td align="center"><%= c_where %></td><td align="center"><%= c_day %></td>
		  <td align="center"><%= c_stime %></td><td align="center"><%= c_etime %></td>
		 <td align="center"><a href="delete.jsp?c_id=<%= c_id %>&c_id_no=<%= c_id_no %>">취소</a></td>
		</tr>
		<%
  		}while(rs.next());
  	}else{
  		//out.println("현재 신청한 수업이 없습니다.");
  		%>
		<tr>
			<td align="center" colspan = 8 >현재 신청한 수업이 없습니다.</td>
		</tr>
		<%
  	}

  	stmt.close();  myConn.close();
}catch(SQLException ex){
    System.err.println("SQLException: " + ex.getMessage());
}
%>
</table></body></html>
<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.*"  %>
<%@ page import="java.util.Calendar"  %>
<%@ page import="java.text.SimpleDateFormat" %>
<html><head><title>수강신청 조회</title></head>
<body>
<%@ include file="top.jsp" %>
<%   if (session_id==null) response.sendRedirect("login.jsp");  %>
<br>
<table width="75%" align="center" border>
<tr><th>과목번호</th><th>분반</th>
<th>과목명</th><th>교수</th><th>학점</th><th>언어</th>
<th>구분</th><th>장소 및 시간</th>
<th>수강 취소</th>
</tr>
<%
String dbdriver = "oracle.jdbc.driver.OracleDriver";
String dburl = "jdbc:oracle:thin:@localhost:1521:orcl";
String user = "db1510188";
String passwd = "test";

Calendar cal = Calendar.getInstance();
int year = cal.get(Calendar.YEAR);
int month =cal.get(Calendar.MONTH)+1;
int semes;
if(month <= 6){
	semes = 1;
}else{
	semes = 2;
}

Connection myConn = null;      
Statement stmt = null;	
ResultSet rs = null;   
String mySQL = "";

try{
	Class.forName(dbdriver);
    myConn=DriverManager.getConnection(dburl, user, passwd);
    
  	
  	//mySQL="select distinct c.c_id,c.c_id_no, c.c_name,p.name,c.c_unit,cl.c_where,t.c_day, t.c_stime,t.c_etime from course c left outer join class cl on c.p_id = cl.p_id and c.c_id = cl.c_id and c.c_id_no = cl.c_id_no left outer join class_time t on c.c_id = t.c_id and c.c_id_no = t.c_id_no left outer join professor p on p.p_id = c.p_id where  c.c_id in (select e.c_id from enroll e where s_id='"+session_id+"')";
  	mySQL = "select * from SelectView sv "
  		  	+"where (sv.c_id,sv.c_id_no) in (select c_id, c_id_no from enroll where s_id = '"+session_id+"') ";
  	stmt = myConn.createStatement();
  	rs = stmt.executeQuery(mySQL);
  	if(rs.next()){
  		do {
  			String c_id = rs.getString("c_id");
			int c_id_no = rs.getInt("c_id_no");	
			String c_name = rs.getString("c_name");
			String p_name = rs.getString("NAME");
			int c_unit = rs.getInt("c_unit");		
			String c_type = rs.getString("c_type");
			String c_major = rs.getString("c_major");
			String c_language = rs.getString("c_language");
			String time = rs.getString("TIME");
			if(p_name == null) p_name = "미정";
			if(c_language == null) c_language = "";
		%>
		<tr>
			<td align="center"><%= c_id %></td> <td align="center"><%= c_id_no %></td> 
			<td align="center"><%= c_name %></td><td align="center"><%= p_name %></td>
			<td align="center"><%= c_unit %></td><td align="center"><%= c_language %></td>
			<td align="center"><%= c_type %></td><td align="center"><%= time %></td>
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
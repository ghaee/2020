<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.*"  %>
<html><head><title>수강신청 입력</title></head>
<body>
<%@ include file="top.jsp" %>
<%   if (session_id==null) response.sendRedirect("login.jsp");  %>

<table width="75%" align="center" border>
<br>
<tr>
<th>학기년도</th><th>학기</th>
<th>과목번호</th><th>분반</th><th>과목명</th><th>학점</th><th>정원</th>
<th>구분</th><th>주관학과</th><th>언어</th><th>수강신청</th>
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
    
  	mySQL = "select * from course where c_semes = 1 and c_id not in (select c_id from enroll where s_id='" + session_id + "') order by c_id ASC";
  	stmt = myConn.createStatement();
  	rs = stmt.executeQuery(mySQL);
  	
  	if (rs != null) {
  		while (rs.next()) {	
  				String c_year = rs.getString("c_year");
  				String c_semes = rs.getString("c_semes");
  				String c_id = rs.getString("c_id");
  				int c_id_no = rs.getInt("c_id_no");			
  				String c_name = rs.getString("c_name");
  				int c_unit = rs.getInt("c_unit");		
  				int c_personnel = rs.getInt("c_personnel");
  				String c_type = rs.getString("c_type");
  				String c_major = rs.getString("c_major");
  				String c_language = rs.getString("c_language");
  				if(c_language == null) c_language = "";
  		%>
  		<tr>
  			<td align="center"><%= c_year %></td><td align="center"><%= c_semes %></td>
  		  <td align="center"><%= c_id %></td> <td align="center"><%= c_id_no %></td> 
  		  <td align="center"><%= c_name %></td><td align="center"><%= c_unit %></td>
  		  <td align="center"><%= c_personnel %></td><td align="center"><%= c_type %></td>
  		  <td align="center"><%= c_major %></td><td align="center"><%= c_language %></td>
  		  <td align="center"><a href="insert_verify.jsp?c_id=<%= c_id %>&c_id_no=<%= c_id_no %>">신청</a></td>
  		</tr>
  		<%
  				}
  		}
  			stmt.close();  myConn.close();
}catch(SQLException ex){
    System.err.println("SQLException: " + ex.getMessage());
}
%>
</table></body></html>
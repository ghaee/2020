<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.*"  %>
<html><head><title>수강신청 입력</title></head>
<body>
<%@ include file="top.jsp" %>
<%   if (session_id==null) response.sendRedirect("login.jsp");  %>

<table width="75%" align="center" border>
<br>
<tr><th>과목번호</th><th>분반</th><th>과목명</th><th>학점</th>
      <th>수강신청</th></tr>
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
    
  	mySQL = "select c_id,c_id_no,c_name,c_unit from course where c_id not in (select c_id from enroll where s_id='" + session_id + "')";
  	stmt = myConn.createStatement();
  	rs = stmt.executeQuery(mySQL);
  	
  	if (rs != null) {
  		while (rs.next()) {	
  				String c_id = rs.getString("c_id");
  				int c_id_no = rs.getInt("c_id_no");			
  				String c_name = rs.getString("c_name");
  				int c_unit = rs.getInt("c_unit");			
  		%>
  		<tr>
  		  <td align="center"><%= c_id %></td> <td align="center"><%= c_id_no %></td> 
  		  <td align="center"><%= c_name %></td><td align="center"><%= c_unit %></td>
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
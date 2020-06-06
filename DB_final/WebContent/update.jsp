<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.*" %>
<html> <head><title>수강신청 사용자 정보 수정</title></head>
<body> <%@ include file="top.jsp" %>
학생 정보
   <table width = "100%" border = "1">
      <tr>
            <td>학번</td>

            <td>비밀번호</td>

            <td>전공</td>

            <td>이름</td>

            <td>이메일</td>
      </tr>
<%
if (session_id==null) response.sendRedirect("login.jsp");

String dbdriver = "oracle.jdbc.driver.OracleDriver";
String dburl = "jdbc:oracle:thin:@localhost:1521:orcl";
String user = "db1510188";
String passwd = "test";

ResultSet rs = null;
Statement stmt = null;
Connection myConn = null;

try{
	Class.forName(dbdriver);
	myConn=DriverManager.getConnection(dburl, user, passwd);
	
	
	String mySQL =  "select * from students where s_id='" + session_id + "'" ;
	
	stmt = myConn.createStatement();
	rs = stmt.executeQuery(mySQL);
	if(rs.next()){
	%>
	      <tr>
	            <td><%= rs.getString("s_id") %></td>
	            <td><%= rs.getString("s_pwd") %></td>
	            <td><%= rs.getString("s_name") %></td>
	            <td><%= rs.getString("s_major") %></td>
	           	<td><%= rs.getString("s_addr") %></td>
	      </tr>
	<%
	}else{
		
	}
	
}catch(Exception e){
	 out.println(e.toString());
     e.printStackTrace();
}finally{
    
    if(rs != null) try { rs.close(); } catch(SQLException ex) {}
    if(stmt != null) try { stmt.close(); } catch(SQLException ex) {}

    
    if(myConn != null) try { myConn.close(); } catch(SQLException ex) {}
}%></table>
<form method="post" action="update_verify.jsp">
	비밀번호 : <input type = "password" name = "new_pwd" value = ""/><br/>
	이메일 : <input type = "text" name = "new_addr" value = ""/><br/>
	<input type = "submit" name = "btn_update" value = "정보 수정">
</form>
</body>
</html>


<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.*" %>
<html><head>
	<title>학생 정보 수정</title>
 <script type="text/javascript">

	function validation() {
		var updateForm = document.update;
        var pwd = updateForm.new_pwd.value;
        var chk_pwd = updateForm.chk_pwd.value;
		
		if(pwd != chk_pwd){
			alert("비밀번호가 일치하지 않습니다.");
			pwd.value = null;
			chk_value = null;
			return false;
			
		}else{
			updateForm.submit();
		}
	}

</script>	
</head>
<body> <%@ include file="top.jsp" %>
<br>
<br>
  <table width="75%" align="center" border="1">
  		<caption><b><font size="6" color="gray">내 정보</font></b></caption>
      <tr>
      		<th>수강 가능한 학점</th>
            <th>학번</th>
            <th>전공</th>
            <th>이름</th>
            <th>학년</th>
            <th>이메일</th>
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
String s_addr = "";
String s_pwd = "";
try{
	Class.forName(dbdriver);
	myConn=DriverManager.getConnection(dburl, user, passwd);
	
	
	String mySQL =  "select * from students where s_id='" + session_id + "'" ;
	
	stmt = myConn.createStatement();
	rs = stmt.executeQuery(mySQL);
	if(rs.next()){
		int s_unit = rs.getInt("s_unit");
		String s_id = rs.getString("s_id");
		s_pwd = rs.getString("s_pwd");
		String s_name = rs.getString("s_name");
		String s_major = rs.getString("s_major");
		int s_grade = rs.getInt("s_grade");
		s_addr = rs.getString("s_addr");
	%>
  		<tr><td align="center"><%= s_unit %></td>
  		<td align="center"><%= s_id %></td><%-- <td align="center"><%= s_pwd %></td> --%>
  		  <td align="center"><%= s_major %></td><td align="center"><%= s_name %></td>
  		  <td align="center"><%= s_grade %></td><td align="center"><%= s_addr %></td>
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
<form name = "update" method="post" action="update_verify.jsp" align="center">
 	<div>
 	<br><br>
        <b><font size="6" color="gray">정보 수정</font></b>
        <br><br><br>
        <label for="mail">E-mail:</label>
        <input type = "text" name = "new_addr" value = <%= s_addr %>/><br/>
        <label for="pwd">비밀번호:</label>
        <input type = "password" name = "new_pwd" value = <%= s_pwd %>/><br/>
        <label for="pwd">비밀번호 확인:</label>
        <input type = "password" name = "chk_pwd" value = <%= s_pwd %>/><br/>
    </div>
    <input type = "button" onclick="validation()" name = "btn_update" value = "정보 수정">
</form>
</body>
</html>


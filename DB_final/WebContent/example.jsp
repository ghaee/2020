<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR" import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
<%
String driver = "oracle.jdbc.driver.OracleDriver";
String url = "jdbc:oracle:thin:@localhost:1521:orcl";
String user = "db1510188";
String password = "test";    // Oracle ���� ���� password �Է�
try {
	Class.forName(driver);
	out.println("1510188");
	out.println("jdbc driver �ε� ����");
	DriverManager.getConnection(url, user, password);
	out.println("1510188");
	out.println("����Ŭ ���� ����");
} catch(ClassNotFoundException e) {
	System.out.println("jdbc driver �ε� ����");
}catch(SQLException e) {
	System.out.println("����Ŭ ���� ����");
}%>
</body>
</html>
<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.*" %>
<html> <head><title> 수강신청 사용자 정보 수정 </title></head>
<body> <%@ include file="top.jsp" %>
<%
String userID=request.getParameter("new_id");
String userPassword=request.getParameter("new_pwd");
String name=request.getParameter("new_name"); 
String address=request.getParameter("new_addr");
String major=request.getParameter("new_major");
%>
<%=userID %>
<%=userPassword %>
<%=name %>
<%=address %>
<%=major %>

</body></html>


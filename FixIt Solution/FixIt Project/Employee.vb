' Name:         Employee.vb
' Programmer:   <your name> on <current date>

Option Explicit On
Option Strict On
Option Infer Off

Public Class Employee
    Public Property EmployeeName As String
    Public Property Salary As Double

    Public Sub New()
        _EmployeeName = String.Empty
        _Salary = 0
    End Sub

    Public Function GetNewSalary(ByVal dblRate As Double) As Double
        ' Calculates the new salary.

        Return _Salary * (1 + dblRate)
    End Function
End Class

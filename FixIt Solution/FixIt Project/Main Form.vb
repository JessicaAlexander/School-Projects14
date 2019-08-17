' Name:         FixIt Project
' Purpose:      Display an employee's new salary.
' Programmer:   <Jessica Alexander> on <01/14/2019>

Option Explicit On
Option Strict On
Option Infer Off

Public Class frmMain
    Private Sub btnCalc_Click(sender As Object, e As EventArgs) Handles btnCalc.Click
        ' Calculates an employee's new salary, which is based on a 5% raise.

        Dim companyEmployee As New Employee
        Dim dblNewSalary As Double

        Double.TryParse(txtCurrentSalary.Text, companyEmployee.Salary)
        dblNewSalary = companyEmployee.GetNewSalary(0.05)
        lblNewSalary.Text = dblNewSalary.ToString("C0")
    End Sub

    Private Sub txtEmpNum_KeyPress(sender As Object, e As KeyPressEventArgs) Handles txtEmpNum.KeyPress, txtCurrentSalary.KeyPress
        ' Accept only numbers and the Backspace key.

        If (e.KeyChar < "0" OrElse e.KeyChar > "9") AndAlso e.KeyChar <> ControlChars.Back Then
            e.Handled = True
        End If
    End Sub

    Private Sub btnExit_Click(sender As Object, e As EventArgs) Handles btnExit.Click
        Me.Close()
    End Sub

    Private Sub txtCurrentSalary_Enter(sender As Object, e As EventArgs) Handles txtCurrentSalary.Enter
        txtCurrentSalary.SelectAll()
    End Sub

    Private Sub txtEmpNum_Enter(sender As Object, e As EventArgs) Handles txtEmpNum.Enter
        txtEmpNum.SelectAll()
    End Sub


    Private Sub ClearNewSalary(sender As Object, e As EventArgs) Handles txtEmpNum.TextChanged, txtCurrentSalary.TextChanged
        lblNewSalary.Text = String.Empty
    End Sub
End Class

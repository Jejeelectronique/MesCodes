Private Sub CommandButton1_Click()
If CommandButton1 = True Then

Call op_bit_a_bit
Call decalage_bit

End If

End Sub



Private Sub bit_a_decaler_Change()

End Sub

Private Sub ByteAA0_Change()

If Len(ByteAA0) > 1 Or (ByteAA0 <> "0" And ByteAA0 <> "1") Then
ByteAA0 = "0"
End If

If ByteAA0 <> "" Then
Me.ByteAA1.SetFocus
End If

Call decalage_bit

End Sub

Private Sub ByteAA1_Change()

If Len(ByteAA1) > 1 Or (ByteAA1 <> "0" And ByteAA1 <> "1") Then
ByteAA1 = "0"
End If

If ByteAA1 <> "" Then
Me.ByteAA2.SetFocus
End If

Call decalage_bit


End Sub

Private Sub ByteAA2_Change()

If Len(ByteAA2) > 1 Or (ByteAA2 <> "0" And ByteAA2 <> "1") Then
ByteAA2 = "0"
End If

If ByteAA2 <> "" Then
Me.ByteAA3.SetFocus
End If

Call decalage_bit

End Sub

Private Sub ByteAA3_Change()

If Len(ByteAA3) > 1 Or (ByteAA3 <> "0" And ByteAA3 <> "1") Then
ByteAA3 = "0"
End If

If ByteAA3 <> "" Then
Me.ByteAA4.SetFocus
End If

Call decalage_bit

End Sub

Private Sub ByteAA4_Change()

If Len(ByteAA4) > 1 Or (ByteAA4 <> "0" And ByteAA4 <> "1") Then
ByteAA4 = "0"
End If

If ByteAA4 <> "" Then
Me.ByteAA5.SetFocus
End If

Call decalage_bit

End Sub

Private Sub ByteAA5_Change()

If Len(ByteAA5) > 1 Or (ByteAA5 <> "0" And ByteAA5 <> "1") Then
ByteAA5 = "0"
End If

If ByteAA5 <> "" Then
Me.ByteAA6.SetFocus
End If

Call decalage_bit

End Sub

Private Sub ByteAA6_Change()

If Len(ByteAA6) > 1 Or (ByteAA6 <> "0" And ByteAA6 <> "1") Then
ByteAA6 = "0"
End If

If ByteAA6 <> "" Then
Me.ByteAA7.SetFocus
End If

Call decalage_bit

End Sub

Private Sub ByteAA7_Change()

If Len(ByteAA7) > 1 Or (ByteAA7 <> "0" And ByteAA7 <> "1") Then
ByteAA7 = "0"
End If

If ByteAA7 <> "" Then
Me.ByteAA0.SetFocus
End If

Call decalage_bit

End Sub

Private Sub ByteRR0_Change()

If Len(ByteRR0) > 1 Or (ByteRR0 <> "0" And ByteRR0 <> "1") Then
ByteRR0 = "0"
End If

Call decalage_bit

End Sub

Private Sub ByteRR1_Change()

If Len(ByteRR1) > 1 Or (ByteRR1 <> "0" And ByteRR1 <> "1") Then
ByteRR1 = "0"
End If

Call decalage_bit

End Sub

Private Sub ByteRR2_Change()

If Len(ByteRR2) > 1 Or (ByteRR2 <> "0" And ByteRR2 <> "1") Then
ByteRR2 = "0"
End If

Call decalage_bit

End Sub

Private Sub ByteRR3_Change()

If Len(ByteRR3) > 1 Or (ByteRR3 <> "0" And ByteRR3 <> "1") Then
ByteRR3 = "0"
End If

Call decalage_bit

End Sub

Private Sub ByteRR4_Change()

If Len(ByteRR4) > 1 Or (ByteRR4 <> "0" And ByteRR4 <> "1") Then
ByteRR4 = "0"
End If

Call decalage_bit

End Sub

Private Sub ByteRR5_Change()

If Len(ByteRR5) > 1 Or (ByteRR5 <> "0" And ByteRR5 <> "1") Then
ByteRR5 = "0"
End If

Call decalage_bit

End Sub

Private Sub ByteRR6_Change()

If Len(ByteRR6) > 1 Or (ByteRR6 <> "0" And ByteRR6 <> "1") Then
ByteRR6 = "0"
End If

Call decalage_bit

End Sub

Private Sub ByteRR7_Change()

If Len(ByteRR7) > 1 Or (ByteRR7 <> "0" And ByteRR7 <> "1") Then
ByteRR7 = "0"
End If

Call decalage_bit

End Sub







Private Sub ComboBox2_Change()

End Sub

Private Sub Frame1_Click()

End Sub

Private Sub MultiPage1_Change()

End Sub

Private Sub nombre_decalage_Change()

End Sub

Private Sub operation_Change()

End Sub

Private Sub TextBox1_Change()



End Sub

Private Sub type_decalage_Change()

End Sub

Private Sub UserForm_Initialize()

    
    Me.ByteB0.SetFocus
    
    ComboBox1.AddItem "AND &"
    ComboBox1.AddItem "OR |"
    ComboBox1.AddItem "XOR |^"
    ComboBox1.AddItem "NAND &^"
    ComboBox1.AddItem "="
    
    
    type_decalage.AddItem "<<"
    type_decalage.AddItem ">>"
    type_decalage.AddItem "="
    
    nombre_decalage.AddItem "1"
    nombre_decalage.AddItem "2"
    nombre_decalage.AddItem "3"
    nombre_decalage.AddItem "4"
    nombre_decalage.AddItem "5"
    nombre_decalage.AddItem "6"
    nombre_decalage.AddItem "7"
    nombre_decalage.AddItem "8"
    
    
    operation.AddItem "Or |"
    operation.AddItem "And &"
    operation.AddItem "And inv &~"
    operation.AddItem "="
    
    TextBox1.Value = 1
    
    
End Sub


Private Sub ByteA0_Change()

 
If Len(ByteA0) > 1 Or (ByteA0 <> "0" And ByteA0 <> "1") Then
ByteA0 = "0"
End If

If ByteA0 <> "" Then
Me.ByteA1.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteA1_Change()

If Len(ByteA1) > 1 Or (ByteA1 <> "0" And ByteA1 <> "1") Then
ByteA1 = "0"
End If

If ByteA1 <> "" Then
Me.ByteA2.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteA2_Change()

If Len(ByteA2) > 1 Or (ByteA2 <> "0" And ByteA2 <> "1") Then
ByteA2 = "0"
End If

If ByteA2 <> "" Then
Me.ByteA3.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteA3_Change()

If Len(ByteA3) > 1 Or (ByteA3 <> "0" And ByteA3 <> "1") Then
ByteA3 = "0"
End If

If ByteA3 <> "" Then
Me.ByteA4.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteA4_Change()

If Len(ByteA4) > 1 Or (ByteA4 <> "0" And ByteA4 <> "1") Then
ByteA4 = "0"
End If

If ByteA4 <> "" Then
Me.ByteA5.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteA5_Change()

If Len(ByteA5) > 1 Or (ByteA5 <> "0" And ByteA5 <> "1") Then
ByteA5 = "0"
End If

If ByteA5 <> "" Then
Me.ByteA6.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteA6_Change()

If Len(ByteA6) > 1 Or (ByteA6 <> "0" And ByteA6 <> "1") Then
ByteA6 = "0"
End If

If ByteA6 <> "" Then
Me.ByteA7.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteA7_Change()

If Len(ByteA7) > 1 Or (ByteA7 <> "0" And ByteA7 <> "1") Then
ByteA7 = "0"
End If

If ByteA7 <> "" Then
Me.ByteB0.SetFocus
End If

Call op_bit_a_bit

End Sub


Private Sub ByteB0_Change()

If Len(ByteB0) > 1 Or (ByteB0 <> "0" And ByteB0 <> "1") Then
ByteB0 = "0"
End If

If ByteB0 <> "" Then
Me.ByteB1.SetFocus
End If

Call op_bit_a_bit

End Sub



Private Sub ByteB1_Change()

If Len(ByteB1) > 1 Or (ByteB1 <> "0" And ByteB1 <> "1") Then
ByteB1 = "0"
End If

If ByteB1 <> "" Then
Me.ByteB2.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteB2_Change()

If Len(ByteB2) > 1 Or (ByteB2 <> "0" And ByteB2 <> "1") Then
ByteB2 = "0"
End If

If ByteB2 <> "" Then
Me.ByteB3.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteB3_Change()

If Len(ByteB3) > 1 Or (ByteB3 <> "0" And ByteB3 <> "1") Then
ByteB3 = "0"
End If

If ByteB3 <> "" Then
Me.ByteB4.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteB4_Change()

If Len(ByteB4) > 1 Or (ByteB4 <> "0" And ByteB4 <> "1") Then
ByteB4 = "0"
End If

If ByteB4 <> "" Then
Me.ByteB5.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteB5_Change()

If Len(ByteB5) > 1 Or (ByteB5 <> "0" And ByteB5 <> "1") Then
ByteB5 = "0"
End If

If ByteB5 <> "" Then
Me.ByteB6.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteB6_Change()

If Len(ByteB6) > 1 Or (ByteB6 <> "0" And ByteB6 <> "1") Then
ByteB6 = "0"
End If

If ByteB6 <> "" Then
Me.ByteB7.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ByteB7_Change()

If Len(ByteB7) > 1 Or (ByteB7 <> "0" And ByteB7 <> "1") Then
ByteB7 = "0"
End If

If ByteB7 <> "" Then
Me.ByteA0.SetFocus
End If

Call op_bit_a_bit

End Sub

Private Sub ComboBox1_Change()

Call op_bit_a_bit

End Sub

Private Sub ResByte0_Change()

If Len(ResByte0) > 1 Or (ResByte0 <> "0" And ResByte0 <> "1") Then
ResByte0 = "0"
End If

Call op_bit_a_bit

End Sub

Private Sub ResByte1_Change()

If Len(ResByte1) > 1 Or (ResByte1 <> "0" And ResByte1 <> "1") Then
ResByte1 = "0"
End If

Call op_bit_a_bit

End Sub

Private Sub ResByte2_Change()

If Len(ResByte2) > 1 Or (ResByte2 <> "0" And ResByte2 <> "1") Then
ResByte2 = "0"
End If

Call op_bit_a_bit

End Sub

Private Sub ResByte3_Change()

If Len(ResByte3) > 1 Or (ResByte3 <> "0" And ResByte3 <> "1") Then
ResByte3 = "0"
End If

Call op_bit_a_bit

End Sub

Private Sub ResByte4_Change()

If Len(ResByte4) > 1 Or (ResByte4 <> "0" And ResByte4 <> "1") Then
ResByte4 = "0"
End If

Call op_bit_a_bit

End Sub

Private Sub ResByte5_Change()

If Len(ResByte5) > 1 Or (ResByte5 <> "0" And ResByte5 <> "1") Then
ResByte5 = "0"
End If

Call op_bit_a_bit

End Sub

Private Sub ResByte6_Change()

If Len(ResByte6) > 1 Or (ResByte6 <> "0" And ResByte6 <> "1") Then
ResByte6 = "0"
End If

Call op_bit_a_bit

End Sub

Private Sub ResByte7_Change()

If Len(ResByte7) > 1 Or (ResByte7 <> "0" And ResByte7 <> "1") Then
ResByte7 = "0"
End If


End Sub


    
    Public Sub op_bit_a_bit()

    
    Dim BByteA(7) As MSForms.TextBox
    Dim BByteB(7) As MSForms.TextBox
    Dim resultat(7) As Integer
    
    Dim operateur As String
    
    Set BByteA(0) = ByteA0
    Set BByteA(1) = ByteA1
    Set BByteA(2) = ByteA2
    Set BByteA(3) = ByteA3
    Set BByteA(4) = ByteA4
    Set BByteA(5) = ByteA5
    Set BByteA(6) = ByteA6
    Set BByteA(7) = ByteA7
    
   
    Set BByteB(0) = ByteB0
    Set BByteB(1) = ByteB1
    Set BByteB(2) = ByteB2
    Set BByteB(3) = ByteB3
    Set BByteB(4) = ByteB4
    Set BByteB(5) = ByteB5
    Set BByteB(6) = ByteB6
    Set BByteB(7) = ByteB7
    TextBox1.Text = "1"
    

    
    
    operateur = ComboBox1.Value
    Dim i As Integer
    
    For i = 0 To 7
    

    
    Select Case operateur
    
    Case "AND &"
    
    If BByteA(i) = 1 And BByteB(i) = 1 Then
    resultat(i) = 1
    Else
    resultat(i) = 0
    End If
    
    Case "OR |"
    
    If BByteA(i) = 1 Or BByteB(i) = 1 Then
    resultat(i) = 1
    Else
    resultat(i) = 0
    End If
    
    Case "XOR |^"
    
    If BByteA(i) = 1 Or BByteB(i) = 1 Then
    resultat(i) = 0
    Else
    resultat(i) = 1
    End If
    
    Case "NAND &^"
    
    If BByteA(i) = 1 And BByteB(i) = 1 Then
    resultat(i) = 0
    Else
    resultat(i) = 1
    End If
    
    
    Case "="
    
    If BByteA(i) = 1 Then
    resultat(i) = 1
    
    Else
    
    resultat(i) = 0
    End If
    
    
    End Select
    
  
    
    
    Next i
    
   
    ResByte0.Value = resultat(0)
    ResByte1.Value = resultat(1)
    ResByte2.Value = resultat(2)
    ResByte3.Value = resultat(3)
    ResByte4.Value = resultat(4)
    ResByte5.Value = resultat(5)
    ResByte6.Value = resultat(6)
    ResByte7.Value = resultat(7)
    
    

    End Sub
    
    
    Public Sub decalage_bit()
    
    
    Dim BByteAA(7) As MSForms.TextBox
    Dim Result(7)  As String
    Dim opera As String
    Dim typeDecalage As String
    Dim nombreDecalage As Integer
    Dim i As Integer
    

    
    opera = operation.Value
    typeDecalage = type_decalage.Value
    nombreDecalage = CInt(nombre_decalage.Value) - 1
    
    
   
    
    Set BByteAA(0) = ByteAA0
    Set BByteAA(1) = ByteAA1
    Set BByteAA(2) = ByteAA2
    Set BByteAA(3) = ByteAA3
    Set BByteAA(4) = ByteAA4
    Set BByteAA(5) = ByteAA5
    Set BByteAA(6) = ByteAA6
    Set BByteAA(7) = ByteAA7
    
    
    
    
    

     For i = 0 To 7
    
    
    
    
    Select Case opera
    
    
       
    
    Case "Or |"
    
    If typeDecalage = "<<" And opera = "=" Then
    
    Result(i) = BByteAA(i)
    
    If i = nombreDecalage Then
    Result(nombreDecalage) = 1
    
    
    

    End If
    End If
    
    
    
    Case "And &"
    
    
    Case "And inv &~"
    
   
    
    
    End Select
    
     Next i
    
    
        ByteRR0.Value = Result(0)
        ByteRR1.Value = Result(1)
        ByteRR2.Value = Result(2)
        ByteRR3.Value = Result(3)
        ByteRR4.Value = Result(4)
        ByteRR5.Value = Result(5)
        ByteRR6.Value = Result(6)
        ByteRR7.Value = Result(7)
        
    
    End Sub





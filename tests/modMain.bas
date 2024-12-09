Attribute VB_Name = "modMain"
Option Explicit

Private Declare Sub ab1_discord_initialize Lib "vb6-discord-rich-presence.dll" (ByVal clientID As String)
Private Declare Sub ab1_discord_release Lib "vb6-discord-rich-presence.dll" ()
Private Declare Sub ab1_discord_presence_set Lib "vb6-discord-rich-presence.dll" (ByVal state As String, ByVal details As String)
Private Declare Sub ab1_discord_presence_clear Lib "vb6-discord-rich-presence.dll" ()

Public Sub Main()
    On Error GoTo ErrorHandler

    Call ab1_discord_initialize("<replace-with-your-client-id>")
    Call ab1_discord_presence_set("Hello!", "Goodbye!")

    Call MsgBox("Press OK to clear")
    Call ab1_discord_presence_clear

    Call ab1_discord_release
    Exit Sub

ErrorHandler:
    Call MsgBox("Error: " & Err.Number & " (" & Err.Description & ")")

End Sub

   M S B A M L   `   `   `  ���� [  WSystem.Windows.Forms, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089Y@clr-namespace:System.Windows.Forms;assembly=System.Windows.FormsSystem.Windows.Forms   Isotope;   5Swiggity_Swag_Autonomous_v2.AvalonEdit.Sample.Window1   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35^ ZWindowsFormsIntegration, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     ` \ICSharpCode.AvalonEdit, Version=4.4.2.9744, Culture=neutral, PublicKeyToken=9cc39be672370310?
avalonEdit.http://icsharpcode.net/sharpdevelop/avalonedit  Lforms@clr-namespace:System.Windows.Forms;assembly=System.Windows.Forms  &   System.Windows.Media.TextOptions    TextFormattingMode$  Display=� � Title$ AvalonEdit.Sample��$	��500��$	��700��.��]� .+�o� $	��Top=�.@�m� $��_File��.@�m� -   $��_Open...��m� -   $��_Save���� m� -   $��E_xit��m� $��_Edit��.@�m� $
��Cu_t�� m� Command$
 Redo��m� $��_Copy��$
 Copy��m� $��_Paste��$ Paste��m� $��_Delete��$ Delete���� m� $��_Undo��$
 Undo��m� $��_Redo��$
 Redo��m� $��Fo_rmat��.@�m� $��
_Word Wrap�� m� IsCheckable .  m� 	IsChecked ��  �� ElementName$ 
textEditor�� �� Path$ WordWrap�m� $��Show _Line Numbers�� .  �� $ 
textEditor��$ ShowLineNumbers�m� $��Show _End of Line�� .  �� $ 
textEditor��$ Options.ShowEndOfLine�c� $	��Top=�.@���  d� 	IsChecked �� $ 
textEditor��$ ShowLineNumbers�.���� $��16�� �� TextAlignment$ Center=�#��  �� $ 
textEditor��$ Options.ShowEndOfLine�.���� $��16��$ Center=�¶�� -   $��highlightingComboBox��	 �� SelectedItem	 �� *SyntaxHighlighting+$ 
textEditor������ =  7ICSharpCode.AvalonEdit.Highlighting.HighlightingManager
   Instance �� Source# Z
 $ HighlightingDefinitions��  � ColumnDefinitions �� $��1* ��� $	��100 �.+�'  !ICSharpCode.AvalonEdit.TextEditor  -   $��
textEditor��$��Consolas)�$
��10pt(�   SyntaxHighlightingM  GICSharpCode.AvalonEdit.Highlighting.HighlightingDefinitionTypeConverter$ C#    Text. Welcome to AvalonEdit!�� $��1��$��4��$
��Left=�]� $��1��$��4 0 0 0q�.+��� -   $��propertyGridComboBox��$	��Top=� �� SelectedIndex$ 0��.@��� .��
TextEditor�� .��
TextArea�� .��	Options7  1System.Windows.Forms.Integration.WindowsFormsHost  -   $��propertyGridHost��$��Right=�   Child. '   !System.Windows.Forms.PropertyGrid  -   propertyGrid��
﻿#pragma checksum "..\..\..\..\Samples\AvalonEdit\Window1.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "07CF7F7D651AF20943B7244C8A292E53"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.34209
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using ICSharpCode.AvalonEdit;
using ICSharpCode.AvalonEdit.Editing;
using ICSharpCode.AvalonEdit.Highlighting;
using ICSharpCode.AvalonEdit.Rendering;
using ICSharpCode.AvalonEdit.Search;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms;
using System.Windows.Forms.Integration;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace Swiggity_Swag_Autonomous_v2.AvalonEdit.Sample {
    
    
    /// <summary>
    /// Window1
    /// </summary>
    public partial class Window1 : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 58 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ComboBox highlightingComboBox;
        
        #line default
        #line hidden
        
        
        #line 69 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ICSharpCode.AvalonEdit.TextEditor textEditor;
        
        #line default
        #line hidden
        
        
        #line 77 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.ComboBox propertyGridComboBox;
        
        #line default
        #line hidden
        
        
        #line 83 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Forms.Integration.WindowsFormsHost propertyGridHost;
        
        #line default
        #line hidden
        
        
        #line 84 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Forms.PropertyGrid propertyGrid;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/Isotope;component/samples/avalonedit/window1.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            
            #line 31 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.openFileClick);
            
            #line default
            #line hidden
            return;
            case 2:
            
            #line 32 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.saveFileClick);
            
            #line default
            #line hidden
            return;
            case 3:
            
            #line 34 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.exitClick);
            
            #line default
            #line hidden
            return;
            case 4:
            this.highlightingComboBox = ((System.Windows.Controls.ComboBox)(target));
            
            #line 61 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
            this.highlightingComboBox.SelectionChanged += new System.Windows.Controls.SelectionChangedEventHandler(this.HighlightingComboBox_SelectionChanged);
            
            #line default
            #line hidden
            return;
            case 5:
            this.textEditor = ((ICSharpCode.AvalonEdit.TextEditor)(target));
            return;
            case 6:
            this.propertyGridComboBox = ((System.Windows.Controls.ComboBox)(target));
            
            #line 78 "..\..\..\..\Samples\AvalonEdit\Window1.xaml"
            this.propertyGridComboBox.SelectionChanged += new System.Windows.Controls.SelectionChangedEventHandler(this.propertyGridComboBoxSelectionChanged);
            
            #line default
            #line hidden
            return;
            case 7:
            this.propertyGridHost = ((System.Windows.Forms.Integration.WindowsFormsHost)(target));
            return;
            case 8:
            this.propertyGrid = ((System.Windows.Forms.PropertyGrid)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}


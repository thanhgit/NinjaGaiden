namespace Map
{
    partial class Home
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Home));
            this.panelMap = new System.Windows.Forms.Panel();
            this.picMap = new System.Windows.Forms.PictureBox();
            this.btnCreate = new System.Windows.Forms.Button();
            this.btnOpen = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.labelCoordinate = new System.Windows.Forms.Label();
            this.panelControl = new System.Windows.Forms.Panel();
            this.tabControl = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.dataGridViewEnemy = new System.Windows.Forms.DataGridView();
            this.Enemy = new System.Windows.Forms.DataGridViewImageColumn();
            this.btnImportObj = new System.Windows.Forms.Button();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.btnImportItems = new System.Windows.Forms.Button();
            this.dataGridViewItems = new System.Windows.Forms.DataGridView();
            this.items = new System.Windows.Forms.DataGridViewImageColumn();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.dataGridViewBoss = new System.Windows.Forms.DataGridView();
            this.boss = new System.Windows.Forms.DataGridViewImageColumn();
            this.btnImportBoss = new System.Windows.Forms.Button();
            this.imageListObject = new System.Windows.Forms.ImageList(this.components);
            this.groupBoxObj = new System.Windows.Forms.GroupBox();
            this.btnUpdateObject = new System.Windows.Forms.Button();
            this.txtContainer = new System.Windows.Forms.TextBox();
            this.txtName = new System.Windows.Forms.TextBox();
            this.txtType = new System.Windows.Forms.TextBox();
            this.txtVy = new System.Windows.Forms.TextBox();
            this.txtVx = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.txtY = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.txtX = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.btnBuildQuadtree = new System.Windows.Forms.Button();
            this.btnBuildGrid = new System.Windows.Forms.Button();
            this.txtWidthCell = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.txtHeightCell = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.lblWidthMap = new System.Windows.Forms.Label();
            this.lblHeightMap = new System.Windows.Forms.Label();
            this.lblRow = new System.Windows.Forms.Label();
            this.lblColumn = new System.Windows.Forms.Label();
            this.panelMap.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picMap)).BeginInit();
            this.panelControl.SuspendLayout();
            this.tabControl.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewEnemy)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewItems)).BeginInit();
            this.tabPage3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewBoss)).BeginInit();
            this.groupBoxObj.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelMap
            // 
            resources.ApplyResources(this.panelMap, "panelMap");
            this.panelMap.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.panelMap.Controls.Add(this.picMap);
            this.panelMap.Name = "panelMap";
            // 
            // picMap
            // 
            this.picMap.BackColor = System.Drawing.SystemColors.ActiveCaption;
            resources.ApplyResources(this.picMap, "picMap");
            this.picMap.Name = "picMap";
            this.picMap.TabStop = false;
            this.picMap.Click += new System.EventHandler(this.picMap_Click);
            this.picMap.Paint += new System.Windows.Forms.PaintEventHandler(this.picMap_Paint);
            this.picMap.MouseMove += new System.Windows.Forms.MouseEventHandler(this.picMap_MouseMove);
            // 
            // btnCreate
            // 
            resources.ApplyResources(this.btnCreate, "btnCreate");
            this.btnCreate.Name = "btnCreate";
            this.btnCreate.UseVisualStyleBackColor = true;
            this.btnCreate.Click += new System.EventHandler(this.btnCreate_Click);
            // 
            // btnOpen
            // 
            resources.ApplyResources(this.btnOpen, "btnOpen");
            this.btnOpen.Name = "btnOpen";
            this.btnOpen.UseVisualStyleBackColor = true;
            this.btnOpen.Click += new System.EventHandler(this.btnOpen_Click);
            // 
            // btnSave
            // 
            resources.ApplyResources(this.btnSave, "btnSave");
            this.btnSave.Name = "btnSave";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // labelCoordinate
            // 
            resources.ApplyResources(this.labelCoordinate, "labelCoordinate");
            this.labelCoordinate.Name = "labelCoordinate";
            // 
            // panelControl
            // 
            this.panelControl.Controls.Add(this.tabControl);
            resources.ApplyResources(this.panelControl, "panelControl");
            this.panelControl.Name = "panelControl";
            // 
            // tabControl
            // 
            this.tabControl.Controls.Add(this.tabPage1);
            this.tabControl.Controls.Add(this.tabPage2);
            this.tabControl.Controls.Add(this.tabPage3);
            resources.ApplyResources(this.tabControl, "tabControl");
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.dataGridViewEnemy);
            this.tabPage1.Controls.Add(this.btnImportObj);
            resources.ApplyResources(this.tabPage1, "tabPage1");
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // dataGridViewEnemy
            // 
            resources.ApplyResources(this.dataGridViewEnemy, "dataGridViewEnemy");
            this.dataGridViewEnemy.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Enemy});
            this.dataGridViewEnemy.Name = "dataGridViewEnemy";
            this.dataGridViewEnemy.ReadOnly = true;
            this.dataGridViewEnemy.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridViewEnemy_CellClick);
            // 
            // Enemy
            // 
            resources.ApplyResources(this.Enemy, "Enemy");
            this.Enemy.Name = "Enemy";
            this.Enemy.ReadOnly = true;
            // 
            // btnImportObj
            // 
            resources.ApplyResources(this.btnImportObj, "btnImportObj");
            this.btnImportObj.Name = "btnImportObj";
            this.btnImportObj.UseVisualStyleBackColor = true;
            this.btnImportObj.Click += new System.EventHandler(this.btnImportObj_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.btnImportItems);
            this.tabPage2.Controls.Add(this.dataGridViewItems);
            resources.ApplyResources(this.tabPage2, "tabPage2");
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // btnImportItems
            // 
            resources.ApplyResources(this.btnImportItems, "btnImportItems");
            this.btnImportItems.Name = "btnImportItems";
            this.btnImportItems.UseVisualStyleBackColor = true;
            this.btnImportItems.Click += new System.EventHandler(this.btnImportItems_Click);
            // 
            // dataGridViewItems
            // 
            this.dataGridViewItems.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewItems.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.items});
            resources.ApplyResources(this.dataGridViewItems, "dataGridViewItems");
            this.dataGridViewItems.Name = "dataGridViewItems";
            this.dataGridViewItems.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridViewItems_CellClick);
            // 
            // items
            // 
            resources.ApplyResources(this.items, "items");
            this.items.Name = "items";
            this.items.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.items.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.dataGridViewBoss);
            this.tabPage3.Controls.Add(this.btnImportBoss);
            resources.ApplyResources(this.tabPage3, "tabPage3");
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // dataGridViewBoss
            // 
            this.dataGridViewBoss.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewBoss.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.boss});
            resources.ApplyResources(this.dataGridViewBoss, "dataGridViewBoss");
            this.dataGridViewBoss.Name = "dataGridViewBoss";
            this.dataGridViewBoss.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridViewBoss_CellClick);
            // 
            // boss
            // 
            resources.ApplyResources(this.boss, "boss");
            this.boss.Name = "boss";
            this.boss.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.boss.SortMode = System.Windows.Forms.DataGridViewColumnSortMode.Automatic;
            // 
            // btnImportBoss
            // 
            resources.ApplyResources(this.btnImportBoss, "btnImportBoss");
            this.btnImportBoss.Name = "btnImportBoss";
            this.btnImportBoss.UseVisualStyleBackColor = true;
            this.btnImportBoss.Click += new System.EventHandler(this.btnImportBoss_Click);
            // 
            // imageListObject
            // 
            this.imageListObject.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            resources.ApplyResources(this.imageListObject, "imageListObject");
            this.imageListObject.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // groupBoxObj
            // 
            this.groupBoxObj.Controls.Add(this.btnUpdateObject);
            this.groupBoxObj.Controls.Add(this.txtContainer);
            this.groupBoxObj.Controls.Add(this.txtName);
            this.groupBoxObj.Controls.Add(this.txtType);
            this.groupBoxObj.Controls.Add(this.txtVy);
            this.groupBoxObj.Controls.Add(this.txtVx);
            this.groupBoxObj.Controls.Add(this.label8);
            this.groupBoxObj.Controls.Add(this.txtY);
            this.groupBoxObj.Controls.Add(this.label6);
            this.groupBoxObj.Controls.Add(this.txtX);
            this.groupBoxObj.Controls.Add(this.label5);
            this.groupBoxObj.Controls.Add(this.label4);
            this.groupBoxObj.Controls.Add(this.label3);
            this.groupBoxObj.Controls.Add(this.label2);
            this.groupBoxObj.Controls.Add(this.label1);
            resources.ApplyResources(this.groupBoxObj, "groupBoxObj");
            this.groupBoxObj.Name = "groupBoxObj";
            this.groupBoxObj.TabStop = false;
            // 
            // btnUpdateObject
            // 
            resources.ApplyResources(this.btnUpdateObject, "btnUpdateObject");
            this.btnUpdateObject.Name = "btnUpdateObject";
            this.btnUpdateObject.UseVisualStyleBackColor = true;
            this.btnUpdateObject.Click += new System.EventHandler(this.btnUpdateObject_Click);
            // 
            // txtContainer
            // 
            resources.ApplyResources(this.txtContainer, "txtContainer");
            this.txtContainer.Name = "txtContainer";
            // 
            // txtName
            // 
            resources.ApplyResources(this.txtName, "txtName");
            this.txtName.Name = "txtName";
            // 
            // txtType
            // 
            resources.ApplyResources(this.txtType, "txtType");
            this.txtType.Name = "txtType";
            // 
            // txtVy
            // 
            resources.ApplyResources(this.txtVy, "txtVy");
            this.txtVy.Name = "txtVy";
            // 
            // txtVx
            // 
            resources.ApplyResources(this.txtVx, "txtVx");
            this.txtVx.Name = "txtVx";
            // 
            // label8
            // 
            resources.ApplyResources(this.label8, "label8");
            this.label8.Name = "label8";
            // 
            // txtY
            // 
            resources.ApplyResources(this.txtY, "txtY");
            this.txtY.Name = "txtY";
            // 
            // label6
            // 
            resources.ApplyResources(this.label6, "label6");
            this.label6.Name = "label6";
            // 
            // txtX
            // 
            resources.ApplyResources(this.txtX, "txtX");
            this.txtX.Name = "txtX";
            // 
            // label5
            // 
            resources.ApplyResources(this.label5, "label5");
            this.label5.Name = "label5";
            // 
            // label4
            // 
            resources.ApplyResources(this.label4, "label4");
            this.label4.Name = "label4";
            // 
            // label3
            // 
            resources.ApplyResources(this.label3, "label3");
            this.label3.Name = "label3";
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.Name = "label2";
            // 
            // label1
            // 
            resources.ApplyResources(this.label1, "label1");
            this.label1.Name = "label1";
            // 
            // label7
            // 
            resources.ApplyResources(this.label7, "label7");
            this.label7.Name = "label7";
            // 
            // btnBuildQuadtree
            // 
            resources.ApplyResources(this.btnBuildQuadtree, "btnBuildQuadtree");
            this.btnBuildQuadtree.Name = "btnBuildQuadtree";
            this.btnBuildQuadtree.UseVisualStyleBackColor = true;
            this.btnBuildQuadtree.Click += new System.EventHandler(this.btnBuildQuadtree_Click);
            // 
            // btnBuildGrid
            // 
            resources.ApplyResources(this.btnBuildGrid, "btnBuildGrid");
            this.btnBuildGrid.Name = "btnBuildGrid";
            this.btnBuildGrid.UseVisualStyleBackColor = true;
            this.btnBuildGrid.Click += new System.EventHandler(this.btnBuildGrid_Click);
            // 
            // txtWidthCell
            // 
            resources.ApplyResources(this.txtWidthCell, "txtWidthCell");
            this.txtWidthCell.Name = "txtWidthCell";
            // 
            // label9
            // 
            resources.ApplyResources(this.label9, "label9");
            this.label9.Name = "label9";
            // 
            // txtHeightCell
            // 
            resources.ApplyResources(this.txtHeightCell, "txtHeightCell");
            this.txtHeightCell.Name = "txtHeightCell";
            // 
            // label10
            // 
            resources.ApplyResources(this.label10, "label10");
            this.label10.Name = "label10";
            // 
            // label11
            // 
            resources.ApplyResources(this.label11, "label11");
            this.label11.Name = "label11";
            // 
            // label12
            // 
            resources.ApplyResources(this.label12, "label12");
            this.label12.Name = "label12";
            // 
            // label13
            // 
            resources.ApplyResources(this.label13, "label13");
            this.label13.Name = "label13";
            // 
            // label14
            // 
            resources.ApplyResources(this.label14, "label14");
            this.label14.Name = "label14";
            // 
            // lblWidthMap
            // 
            resources.ApplyResources(this.lblWidthMap, "lblWidthMap");
            this.lblWidthMap.Name = "lblWidthMap";
            // 
            // lblHeightMap
            // 
            resources.ApplyResources(this.lblHeightMap, "lblHeightMap");
            this.lblHeightMap.Name = "lblHeightMap";
            // 
            // lblRow
            // 
            resources.ApplyResources(this.lblRow, "lblRow");
            this.lblRow.Name = "lblRow";
            // 
            // lblColumn
            // 
            resources.ApplyResources(this.lblColumn, "lblColumn");
            this.lblColumn.Name = "lblColumn";
            // 
            // Home
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.lblColumn);
            this.Controls.Add(this.lblHeightMap);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.lblRow);
            this.Controls.Add(this.lblWidthMap);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.txtHeightCell);
            this.Controls.Add(this.txtWidthCell);
            this.Controls.Add(this.btnBuildGrid);
            this.Controls.Add(this.btnBuildQuadtree);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.groupBoxObj);
            this.Controls.Add(this.panelControl);
            this.Controls.Add(this.labelCoordinate);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.btnOpen);
            this.Controls.Add(this.btnCreate);
            this.Controls.Add(this.panelMap);
            this.MaximizeBox = false;
            this.Name = "Home";
            this.ShowIcon = false;
            this.Load += new System.EventHandler(this.Home_Load);
            this.panelMap.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picMap)).EndInit();
            this.panelControl.ResumeLayout(false);
            this.tabControl.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewEnemy)).EndInit();
            this.tabPage2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewItems)).EndInit();
            this.tabPage3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewBoss)).EndInit();
            this.groupBoxObj.ResumeLayout(false);
            this.groupBoxObj.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panelMap;
        private System.Windows.Forms.PictureBox picMap;
        private System.Windows.Forms.Button btnCreate;
        private System.Windows.Forms.Button btnOpen;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Label labelCoordinate;
        private System.Windows.Forms.Panel panelControl;
        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Button btnImportObj;
        private System.Windows.Forms.ImageList imageListObject;
        private System.Windows.Forms.DataGridView dataGridViewEnemy;
        private System.Windows.Forms.DataGridView dataGridViewItems;
        private System.Windows.Forms.GroupBox groupBoxObj;
        private System.Windows.Forms.TextBox txtType;
        private System.Windows.Forms.TextBox txtVy;
        private System.Windows.Forms.TextBox txtVx;
        private System.Windows.Forms.TextBox txtY;
        private System.Windows.Forms.TextBox txtX;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Button btnImportItems;
        private System.Windows.Forms.Button btnImportBoss;
        private System.Windows.Forms.DataGridView dataGridViewBoss;
        private System.Windows.Forms.DataGridViewImageColumn items;
        private System.Windows.Forms.DataGridViewImageColumn boss;
        private System.Windows.Forms.DataGridViewImageColumn Enemy;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtContainer;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button btnBuildQuadtree;
        private System.Windows.Forms.Button btnUpdateObject;
        private System.Windows.Forms.Button btnBuildGrid;
        private System.Windows.Forms.TextBox txtWidthCell;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox txtHeightCell;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label lblWidthMap;
        private System.Windows.Forms.Label lblHeightMap;
        private System.Windows.Forms.Label lblRow;
        private System.Windows.Forms.Label lblColumn;
    }
}
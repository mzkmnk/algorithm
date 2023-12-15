from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas
from reportlab.platypus import SimpleDocTemplate, Table, TableStyle
from reportlab.lib import colors

# ReportLabを使用してPDFにテーブルを追加する関数
def create_pdf_with_table(html, file_path):
    # HTMLからテーブルデータを抽出
    tables = extract_table_from_html(html)

    # PDFドキュメントを作成
    doc = SimpleDocTemplate(file_path, pagesize=letter)
    elements = []

    # テーブルをPDFに追加
    for table in tables:
        # ReportLabのテーブル形式にデータを変換
        data = [table.columns.to_list()] + table.values.tolist()
        t = Table(data)

        # テーブルスタイルの設定
        style = TableStyle([
            ('BACKGROUND', (0, 0), (-1, 0), colors.grey),
            ('TEXTCOLOR',(0,0),(-1,0),colors.whitesmoke),
            ('ALIGN',(0,0),(-1,-1),'CENTER'),
            ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
            ('BOTTOMPADDING', (0, 0), (-1, 0), 12),
            ('BACKGROUND',(0,1),(-1,-1),colors.beige),
            ('GRID',(0,0),(-1,-1),1,colors.black)
        ])
        t.setStyle(style)

        elements.append(t)

    # PDFに要素を追加して保存
    doc.build(elements)

# PDFファイルのパス
pdf_file_path = "/mnt/data/table_example_reportlab.pdf"

# ReportLabを使用してPDFを生成
create_pdf_with_table(html, pdf_file_path)

# 生成されたPDFファイルのパスを返す
pdf_file_path
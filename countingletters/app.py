import tkinter as tk
import ttkbootstrap as ttk # ttkbootstrap를 ttk라는 이름으로 가져옵니다.
from tkinter import filedialog, messagebox
import json

class ResumeApp:
    def __init__(self, root):
        self.root = root
        self.root.title("파이썬 자기소개서 작성기")
        self.root.geometry("1000x700")

        # --- 데이터 구조 ---
        self.docs = {}
        self.current_doc_id = None
        self.current_filepath = None

        # --- 메인 레이아웃 ---
        self.paned_window = ttk.PanedWindow(root, orient=tk.HORIZONTAL)
        self.paned_window.pack(fill=tk.BOTH, expand=True)

        # 1. 왼쪽 사이드바 (탭 목록)
        sidebar_frame = ttk.Frame(self.paned_window, width=250, padding=10)
        sidebar_header = ttk.Frame(sidebar_frame)
        ttk.Label(sidebar_header, text="자기소개서 목록", font=("-size 12 -weight bold")).pack(side=tk.LEFT)
        ttk.Button(sidebar_header, text="+", width=2, command=self.add_doc, bootstyle="info").pack(side=tk.RIGHT)
        sidebar_header.pack(fill=tk.X, pady=(0, 10))
        
        self.doc_listbox = tk.Listbox(sidebar_frame, font=("-size 11"), height=4)
        self.doc_listbox.pack(fill=tk.BOTH, expand=True)
        self.doc_listbox.bind("<<ListboxSelect>>", self.select_doc)

        sidebar_footer = ttk.Frame(sidebar_frame)
        ttk.Button(sidebar_footer, text="불러오기", command=self.load_file, bootstyle="secondary").pack(side=tk.LEFT, expand=True, fill=tk.X, padx=(0,2))
        ttk.Button(sidebar_footer, text="저장", command=self.save_file, bootstyle="primary").pack(side=tk.LEFT, expand=True, fill=tk.X, padx=(2,0))
        sidebar_footer.pack(fill=tk.X, pady=(10, 0))
        
        self.paned_window.add(sidebar_frame)

        # 2. 오른쪽 콘텐츠 영역
        content_main_frame = ttk.Frame(self.paned_window, padding=10)
        self.title_var = tk.StringVar()
        title_entry = ttk.Entry(content_main_frame, textvariable=self.title_var, font=("-size 16 -weight bold"))
        title_entry.pack(fill=tk.X, pady=(0, 10))
        self.title_var.trace_add("write", self.update_doc_title)
        
        # 스크롤 가능한 캔버스 추가
        canvas = tk.Canvas(content_main_frame, highlightthickness=0)
        scrollbar = ttk.Scrollbar(content_main_frame, orient="vertical", command=canvas.yview, bootstyle="round")
        self.content_frame = ttk.Frame(canvas)

        self.content_frame.bind("<Configure>", lambda e: canvas.configure(scrollregion=canvas.bbox("all")))
        canvas.create_window((0, 0), window=self.content_frame, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)

        canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        ttk.Button(content_main_frame, text="+ 문항 추가하기", command=self.add_question, bootstyle="outline-secondary").pack(fill=tk.X, pady=5)
        
        self.paned_window.add(content_main_frame)

        # 단축키 바인딩
        self.root.bind("<Command-s>", self.save_file)
        self.root.bind("<Control-s>", self.save_file)

        # 초기 문서 생성
        self.add_doc("새 자기소개서")

    # (이하 add_doc, select_doc 등 다른 함수들은 이전 코드와 동일합니다)
    def add_doc(self, title="새 자기소개서"):
        doc_id = str(id(title)) # 간단한 ID 생성
        self.docs[doc_id] = {"title": title, "questions": []}
        self.doc_listbox.insert(tk.END, title)
        self.doc_listbox.selection_clear(0, tk.END)
        self.doc_listbox.selection_set(tk.END)
        self.select_doc()

    def select_doc(self, event=None):
        selected_indices = self.doc_listbox.curselection()
        if not selected_indices:
            self.current_doc_id = None
            self.render_content()
            return
        
        selected_title = self.doc_listbox.get(selected_indices[0])
        for doc_id, data in self.docs.items():
            if data['title'] == selected_title:
                self.current_doc_id = doc_id
                break
        self.render_content()

    def update_doc_title(self, *args):
        if not self.current_doc_id: return
        new_title = self.title_var.get()
        self.docs[self.current_doc_id]['title'] = new_title
        
        selected_indices = self.doc_listbox.curselection()
        if selected_indices:
            self.doc_listbox.delete(selected_indices[0])
            self.doc_listbox.insert(selected_indices[0], new_title)
            self.doc_listbox.selection_set(selected_indices[0])

    def render_content(self):
        for widget in self.content_frame.winfo_children():
            widget.destroy()
            
        if not self.current_doc_id: 
            self.title_var.set("")
            return
        
        doc_data = self.docs[self.current_doc_id]
        self.title_var.set(doc_data['title'])

        for i, q in enumerate(doc_data['questions']):
            q_frame = ttk.Labelframe(self.content_frame, text=f" {i+1}. {q['title']} ")
            q_frame.pack(fill=tk.X, padx=10, pady=10, expand=True)

            text_area = tk.Text(q_frame, height=8, wrap=tk.WORD, relief=tk.FLAT, padx=5, pady=5)
            text_area.insert("1.0", q['content'])
            text_area.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
            
            # Text 위젯 주변에 테두리 효과를 주기 위한 Frame
            border_frame = ttk.Frame(q_frame, bootstyle="secondary", padding=1)
            border_frame.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
            text_area.pack_forget() # 기존 pack 제거
            border_frame.add(text_area) # Frame 안에 Text 위젯 추가

            count_label = ttk.Label(q_frame, text=f"0 / {q['maxLength']}")
            count_label.pack(anchor='e', padx=5, pady=(0, 5))

            text_area.bind("<KeyRelease>", lambda e, area=text_area, label=count_label, question=q: self.update_char_count(area, label, question))
            self.update_char_count(text_area, count_label, q)


    def add_question(self):
        if not self.current_doc_id: return
        self.docs[self.current_doc_id]['questions'].append({
            "title": "새 문항", "content": "", "maxLength": 1000
        })
        self.render_content()

    def update_char_count(self, text_area, count_label, question):
        content = text_area.get("1.0", "end-1c")
        char_count = len(content)
        question['content'] = content
        
        count_label.config(text=f"{char_count} / {question['maxLength']}")
        if char_count > question['maxLength']:
            count_label.config(bootstyle="danger")
        else:
            count_label.config(bootstyle="default")

    def save_file(self, event=None):
        if not self.current_filepath:
            filepath = filedialog.asksaveasfilename(defaultextension=".json", filetypes=[("JSON Files", "*.json")])
            if not filepath: return
            self.current_filepath = filepath
        
        try:
            with open(self.current_filepath, 'w', encoding='utf-8') as f:
                json.dump(self.docs, f, ensure_ascii=False, indent=2)
            self.root.title(f"파이썬 자기소개서 작성기 - {self.current_filepath}")
        except Exception as e:
            messagebox.showerror("저장 오류", f"파일 저장 중 오류가 발생했습니다:\n{e}")

    def load_file(self):
        filepath = filedialog.askopenfilename(filetypes=[("JSON Files", "*.json")])
        if not filepath: return

        try:
            with open(filepath, 'r', encoding='utf-8') as f: self.docs = json.load(f)
            self.current_filepath = filepath
            self.doc_listbox.delete(0, tk.END)
            for doc_id, data in self.docs.items(): self.doc_listbox.insert(tk.END, data['title'])
            if self.doc_listbox.size() > 0:
                self.doc_listbox.selection_set(0)
                self.select_doc()
            self.root.title(f"파이썬 자기소개서 작성기 - {self.current_filepath}")
        except Exception as e:
            messagebox.showerror("불러오기 오류", f"파일 불러오는 중 오류가 발생했습니다:\n{e}")


if __name__ == "__main__":
    # 'litera' 테마를 적용한 새로운 창을 만듭니다.
    root = ttk.Window(themename="litera")
    # root = ttk.Window(themename="darkly") # superhero
    app = ResumeApp(root)
    root.mainloop()
from django.shortcuts import redirect, render, get_object_or_404
from .models import Memo
from .forms import MemoForm
# Create your views here.

def index(request):
    memos = Memo.objects.all() # DB에 저장된 전체 memo 가져오기
    context = {
        'memos' : memos,
    }
    return render(request, 'memos/index.html', context) # context로 템플릿에 전달


def create(request):
    if request.method == 'POST': # POST 요청인 경우, 작성된 메모를 저장하는 요청임
        form = MemoForm(request.POST)
        if form.is_valid():
            memo = form.cleaned_data.get('memo')
            summary = form.cleaned_data.get('summary')
            memo = Memo(memo=memo, summary=summary)
            memo.save()
            return redirect('memos:index')
    else: # GET 요청인 경우, 새 메모를 작성하는 템플릿 보여주기
        form = MemoForm()
        
    context = {
        'form' : form,
    }
    return render(request, 'memos/create.html', context)

def detail(request, pk):
    memo = get_object_or_404(Memo, pk=pk) # 해당되는 memo가 없으면 404 에러
    context = {
        'memo' : memo,
    }
    return render(request, 'memos/detail.html', context)

def delete(request, pk):
    memo = get_object_or_404(Memo,pk=pk)
    memo.delete()
    return redirect("memos:index")    
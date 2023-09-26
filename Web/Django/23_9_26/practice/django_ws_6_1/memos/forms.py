from django import forms


# Create your models here.
class MemoForm(forms.Form):
    summary = forms.CharField(
        max_length = 20,
        widget = forms.TextInput(
            attrs = {
                'placeholder':'summary',
            }
        )
    )
    memo = forms.CharField(
        widget = forms.Textarea(
            attrs = {
                'placeholder':'memo',
                'rows':5,
                'cols':50,
            }
        )
    )
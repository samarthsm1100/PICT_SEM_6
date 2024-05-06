import random
import re

responses = {
    'greetings': ['Hello, How can I help You ?', 'Greetings from Chatbot! How can I help you ?'],
    'broken' : ['Broken Glass so buy a new one :)', 'Okay so your glass is broken as of your mind'],
    'new' : ['yes, we have got variety of new laptops', 'What brand are you looking for ?']
}

def respond(query):
    query = query.lower()
    if re.search(r"\b(?:hello|hi)\b", query):
        return random.choice(responses["greetings"])
    elif re.search(r"\b(?:broken)\b", query):
        return random.choice(responses["broken"])
    else:
        return "umm ?"

ans = respond("Hi Sir")
print(ans)

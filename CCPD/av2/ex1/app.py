from flask import Flask, request, jsonify
app = Flask(__name__)

def mph_to_kmh(mph):
    return (mph * 1.609)

def kmh_to_mph(kmh):
    return (kmh / 1.609)


@app.route('/api/tokmh')
def to_kmh():
    data = request.get_json()
    data['speed'] = mph_to_kmh(data['speed'])

    return jsonify(data)

@app.route('/api/tomph')
def to_mph():
    data = request.get_json()
    data['speed'] = kmh_to_mph(data['speed'])

    return jsonify(data)
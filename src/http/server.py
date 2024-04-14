from http.server import BaseHTTPRequestHandler, HTTPServer
import argparse
import sys

parser = argparse.ArgumentParser()
parser.add_argument('-n', '--name', dest='name', action='store')

args = parser.parse_args()

host = "192.168.5.1"
host = "localhost"
port = 5000

class Server(BaseHTTPRequestHandler):
	def do_GET(self):
		self.send_response(200)
		self.send_header("Content-type", "text/html")
		self.end_headers()
		self.wfile.write(bytes(args.name, "utf-8"))
		sys.stdout.write(self.client_address[0])
		sys.stdout.flush()
		#print(self.requestline)
		

server = HTTPServer((host, port), Server)
server.handle_request()

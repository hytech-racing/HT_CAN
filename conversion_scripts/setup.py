from setuptools import setup, find_packages

setup(
    name="conversion_scripts",
    version="2.0",
    packages=find_packages(),
    scripts=["can_to_mcap.py", "dbc_to_proto.py", "json_to_dbc.py", "sym_to_json.py"],
)

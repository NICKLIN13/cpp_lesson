import os
import shutil

# Set your directory here
dir_path = './'

for filename in os.listdir(dir_path):
    if filename.endswith('.md'):
        try:
            date, name = filename.split('_', 1)
        except Exception:
            continue
        new_dir = os.path.join(dir_path, date)
        os.makedirs(new_dir, exist_ok=True)
        shutil.move(os.path.join(dir_path, filename), os.path.join(new_dir, name))
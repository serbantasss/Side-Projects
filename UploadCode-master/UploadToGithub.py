from github import GithubException
import os

def upload_to_github(repo, git_path, content, problem_info=''):
    folder_path = '/'.join(git_path.split('/')[:-1])

    try:
        all_paths = [file.path for file in repo.get_contents(folder_path)]

    except GithubException:
        if problem_info:
            repo.create_file(f'{folder_path}/__info.txt', "Created info.txt", problem_info, branch="main")

        all_paths = []

    if git_path not in all_paths:
        repo.create_file(git_path, 'Committing files', content, branch="main")
        print(git_path, 'CREATED')
    else:
        print(git_path, 'ALREADY EXISTS')

def create_local_file(path, file_name, content, problem_info=''):
    print(path)
    current_directory = os.getcwd()
    final_directory = os.path.join(current_directory, path)
    if not os.path.exists(final_directory):
        os.makedirs(final_directory)
    with open(f'{path}/{file_name}','w') as f:
        f.write(content)
    with open(f'{path}/__info.txt','w') as f:
        f.write(problem_info)
